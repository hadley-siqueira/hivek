#include <iostream>
#include <sstream>

#include "parser.h"
#include "scanner.h"
#include "module.h"
#include "data_directive.h"
#include "align_directive.h"
#include "label.h"
#include "instruction.h"

Parser::Parser() {
    for (int i = 0; i < 32; ++i) {
        std::stringstream s;
        s << i;
        regs_map[s.str()] = i;
    }

    opcodes_map["add"] = CMD_INST_ADD;
    opcodes_map["addi"] = CMD_INST_ADDI;
}

Module* Parser::parse(std::string path) {
    Scanner sc;

    idx = 0;
    tokens = sc.read(path);

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].to_str() << '\n';
    }

    return parse_module();
}

Module* Parser::parse_module() {
    Module* mod = new Module();

    while (true) {
        if (lookahead(TK_DOT)) {
            mod->add_to_section(parse_directive());
        } else if (lookahead(TK_ID)) {
            mod->add_to_section(parse_label_or_instruction());
        } else {
            break;
        }
    }

    return mod;
}

Command* Parser::parse_directive() {
    Command* inst = nullptr;
    expect(TK_DOT);

    if (lookahead("byte")) {
        inst = parse_byte_directive();
    } else if (lookahead("int")) {
        inst = parse_int_directive();
    } else if (lookahead("string")) {
        parse_string_directive();
    } else if (lookahead("align")) {
        inst = parse_align_directive();
    }

    return inst;
}

Command* Parser::parse_align_directive() {
    std::stringstream ss;
    int value;

    expect("align");
    expect(TK_NUMBER);

    ss << matched.get_lexeme();
    ss >> value;

    return new AlignDirective(value);
}

Command* Parser::parse_byte_directive() {
    DataDirective* dir = new DataDirective(CMD_BYTE_DIRECTIVE);
    expect("byte");

    dir->add_value(parse_byte_literal());

    while (match(TK_COMMA)) {
        dir->add_value(parse_byte_literal());
    }

    return dir;
}

Command* Parser::parse_int_directive() {
    DataDirective* dir = new DataDirective(CMD_INT_DIRECTIVE);
    expect("int");

    dir->add_value(parse_int_literal());

    while (match(TK_COMMA)) {
        dir->add_value(parse_int_literal());
    }

    return dir;
}

void Parser::parse_string_directive() {
    expect("string");
    expect(TK_STRING);
}

Token Parser::parse_byte_literal() {
    expect(TK_NUMBER);
    return matched;
}

Token Parser::parse_int_literal() {
    expect(TK_NUMBER);
    return matched;
}

Command* Parser::parse_label_or_instruction() {
    std::string id = parse_id();

    if (match(TK_COLON)) {
        return new Label(id);
    } 

    return parse_instruction(id);
}

Command* Parser::parse_instruction(std::string op) {
    if (op == "add") {
        return parse_instruction_reg_reg_reg(opcodes_map[op]);
    } else if (op == "addi") {
        return parse_instruction_reg_reg_immd(opcodes_map[op]);
    }

    return nullptr;
}

Command* Parser::parse_instruction_reg_reg_reg(int kind) {
    Instruction* inst = new Instruction(kind);

    inst->set_dest(parse_register());
    expect(TK_COMMA);

    inst->set_src1(parse_register());
    expect(TK_COMMA);

    inst->set_src2(parse_register());
    return inst;
}

Command* Parser::parse_instruction_reg_reg_immd(int kind) {
    Instruction* inst = new Instruction(kind);

    inst->set_dest(parse_register());
    expect(TK_COMMA);

    inst->set_src1(parse_register());
    expect(TK_COMMA);

    if (match(TK_NUMBER)) {
        inst->set_src2(new Value(VAL_NUMBER, matched.get_lexeme()));
    }

    return inst;
}

Value* Parser::parse_register() {
    Value* r = nullptr;

    if (lookahead(TK_ID)) {
        parse_id();
    } else if (match(TK_MODULO)) {
        expect(TK_NUMBER);

        if (regs_map.count(matched.get_lexeme()) > 0) {
            r = new Value(VAL_REG, matched.get_lexeme());
        }
    }

    return r;
}

std::string Parser::parse_id() {
    std::stringstream id;
    expect(TK_ID);
    id << matched.get_lexeme();

    while (match(TK_DOT)) {
        expect(TK_ID);
        id << '.' << matched.get_lexeme();
    }

    if (match(TK_HASH)) {
        expect(TK_ID);
        id << "#" << matched.get_lexeme();
    }

    if (match(TK_LT)) {
        id << '<' << parse_id_list();
        expect(TK_GT);
        id << '>';
    }

    if (match(TK_LPAREN)) {
        id << '(' << parse_id_list();
        expect(TK_RPAREN);
        id << ')';
    }

    return id.str();
}

std::string Parser::parse_id_list() {
    std::stringstream l;

    l << parse_id();

    while (match(TK_COMMA)) {
        l << ", " << parse_id();
    }

    return l.str();
}

void Parser::expect(int kind) {
    if (match(kind)) {
        return;
    }

    //log_error_and_exit(error_unexpected_token(path, tokens[idx]));
    std::cout << "expect error\n";
    exit(0);
}

void Parser::expect(std::string lexeme) {
    if (match(lexeme)) {
        return;
    }

    //log_error_and_exit(error_unexpected_token(path, tokens[idx]));
    std::cout << "expect error\n";
    exit(0);
}

bool Parser::match(int kind) {
    if (lookahead(kind)) {
        matched = tokens[idx];
        advance();
        return true;
    }

    return false;
}

bool Parser::match(std::string lexeme) {
    if (lookahead(lexeme)) {
        matched = tokens[idx];
        advance();
        return true;
    }

    return false;
}

bool Parser::lookahead(int kind) {
    return tokens[idx].get_kind() == kind;
}

bool Parser::lookahead(std::string lexeme) {
    return tokens[idx].get_lexeme() == lexeme;
}

void Parser::advance() {
    if (idx < tokens.size()) {
        ++idx;
    }
}

