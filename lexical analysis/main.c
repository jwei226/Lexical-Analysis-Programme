// main.c
#include "scanner.h"
#include <stdio.h>

static void run(const char* source) {
    initScanner(source);
    int line = -1;
    // ��ӡToken, ����TOKEN_EOFΪֹ
    for (;;) {
        // ������һ��Token
        Token token = scanToken();
        // ��ӡ���Token����Ϣ
        if (token.line != line) {
            printf("%4d ", token.line);
            line = token.line;
        }
        else {
            printf("   | ");
        }
        printf("%2d '%.*s'\n", token.type, token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }
}

static void repl() {
    // ���û��������û�ÿ����һ�д��룬����һ�д��룬����������
    // repl��"read evaluate print loop"����д
}

static char* readFile(const char* path) {
    // �û������ļ������������ļ������ݶ����ڴ棬����ĩβ���'\0'
    // ע��: ����Ӧ��ʹ�ö�̬�ڴ���䣬���Ӧ������ȷ���ļ��Ĵ�С��
}

static void runFile(const char* path) {
    // ����'.c'�ļ�:�û������ļ��������������ļ�������������
    char* source = readFile(path);
    run(source);
    free(source);
}

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        // ./scanner û�в���,����뽻��ʽ����
        repl();
    }
    else if (argc == 2) {
        // ./scanner file �����һ������,����������ļ�
        runFile(argv[1]);
    }
    else {
        fprintf(stderr, "Usage: scanner [path]\n");
        exit(1);
    }

    return 0;
}