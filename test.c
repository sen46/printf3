#include <stdio.h>

void gpt_output(void);
void gpt_op(void);

int main()
{
	printf("%c\n", 'a');
	printf("nodot=%3c=\n", 'a');
	// printf("nodot=%0c=\n", 'a');
	// printf("dot=%3.c=\n", 'a');
	// printf("%.5c\n", 'a');
	printf("%s\n", "abc");
	printf("nodot=%5s=\n", "abc"); // 長さが長すぎる場合はspaceで埋める
	printf("nodot=%1s=\n", "def"); // 長さ指定が短すぎる場合は全部出力
	// printf("nodot=%0s=\n", "def"); // 長さ指定が短すぎる場合は全部出力
	printf("1dot=%5.s=\n", "ghi"); // 5 つのスペースを出力
	printf("2dot=%1.s=\n", "jhk"); // 1 つのスペースを出力
	// printf("nodot=%0.s=\n", "jhk");
	printf("3dot=%.s=\n", "lmn"); // 何も出力しない
	printf("4dot=%.3s=\n", "opqr"); // 3 文字を出力
	printf("5dot=%.5s=\n", "stu"); // 3 文字を出力、すべての文字を出力
	printf("6dot=%.0s=\n", "vwx"); // 0 文字を出力
	printf("7dot=%.5s=\n", ""); // 0 文字を出力
	printf("xxxxxxxxxxdot=%5.3s=\n", "abcdefghi"); // 0 文字を出力



	printf("\n\n\n");
	printf("%i\n", 42); // そのまま出力
	printf("%d\n", -42); // そのまま出力
	printf("nodot=%4i=\n", 42); // 2 枠スペース、右詰
	printf("nodot=%4d=\n", -42); // 1 枠スペース
	printf("1dot=%4.i=\n", 42); // 2枠スペース
	printf("2dot=%4.d=\n", -42); // 1枠スペース
	printf("3dot=%1.i=\n", 42); // すべてを出力
	printf("4dot=%1.d=\n", -42); // すべてを出力
	// printf("5dot=%0.i=\n", 42);
	// printf("6dot=%0.d=\n", -42);
	printf("7dot=%.4i=\n", 42); // 0042が出力される, %04と同じ挙動
	printf("7dot=%.4i=\n", -42); // -0042が出力される
	printf("8dot=%.1i=\n", 42); // そのまま出力
	printf("9dot=%.1d=\n", -42); // そのまま出力
	printf("10dot=%.0i=\n", 42); // そのまま出力
	printf("11dot=%.0d=\n", -42); // そのまま出力
	printf("\n\n\n");



	printf("%p\n", (void *)255);
	printf("1nodot=%1p=\n", (void *)255); // そのまま出力
	printf("5nodot=%5p=\n", (void *)255); // そのまま出力
	// printf("dot=%1.p=\n", (void *)255);
	// printf("dot=%5.p=\n", (void *)255);
	// printf("dot=%.1p=\n", (void *)2147483647);
	// printf("dot=%.5p=\n", (void *)2147483647);
	printf("\n\n\n");







	printf("1x=%x=\n", 255); // そのまま出力
	printf("2dotx=%.x=\n", 255); // そのまま出力
	printf("3dotx=%1.x=\n", 255); // そのまま出力
	printf("4dotx=%5.x=\n", 255); // ３枠スペース
	printf("5dotx=%.1x=\n", 255); // そのまま出力
	printf("6dotx=%.5x=\n", 255); // 000ffが出力
	// printf("6dotx=%0.5x=\n", 255);
	printf("7nodotx=%1x=\n", 255); // そのまま出力
	printf("8nodotx=%5x=\n", 255); // ３枠スペース
	printf("\n\n\n");




	printf("minus=%-c=\n", 'a');
	printf("minus=%-s=\n", "abc");
	printf("minus=%-i=\n", 42);
	printf("minus=%-d=\n", -42);
	printf("minus=%-p=\n", (void *)2147483647);
	printf("minus=%-x=\n", 255);
	// printf("%+c\n", 'a');
	// printf("%+s\n", "abc");
	printf("plus=%+i=\n", 42);
	printf("plus=%+d=\n", -42);
	// printf("%+p\n", (void *)2147483647);
	// printf("%+x\n", 255);
	// printf("% c\n", 'a');
	// printf("% s\n", "abc");
	printf("blank=% i=\n", 42);
	printf("blank=% d=\n", -42);
	// printf("% p\n", (void *)2147483647);
	// printf("% x\n", 255);
	// printf("%#c\n", 'a');
	 // printf("%#s\n", "abc");
	// printf("%#i\n", 42);
	// printf("%#d\n", -42);
	// printf("%#p\n", (void *)2147483647);
	printf("hash=%#x=\n", 255);
	printf("hash=%#x=\n", 0);
	// printf("%0c\n", 'a');
	// printf("%0s\n", "abc");
	 printf("zero=%0i=\n", 42);
	printf("zero=%0d=\n", -42);
	// printf("%0p\n", (void *)2147483647);
	printf("zero=%0x=\n", 255);

	// gpt_output();
	// gpt_op();
	printf("xxxxxxxxxx=%-1.2d=\n", 123);
}

void gpt_output(void)
{
    printf("== %%c（文字）==\n");
    printf("1: [%c]\n", 'A');
    printf("2: [%3c]\n", 'A');     // 右寄せ（幅3）
    printf("3: [%-3c]\n", 'A');    // 左寄せ（幅3）
    // printf("4: [%0c]\n", 'A');  // 非対応（未定義動作）

    // --- %s: 文字列 ---
    printf("\n== %%s（文字列）==\n");
    printf("1: [%s]\n", "hello");
    printf("2: [%10s]\n", "hi");       // 幅10右寄せ
    printf("3: [%-10s]\n", "hi");      // 幅10左寄せ
    printf("4: [%.3s]\n", "abcdef");   // 最大3文字
    printf("5: [%10.3s]\n", "abcdef"); // 幅10、最大3文字
    printf("6: [%.0s]\n", "abc");      // 空文字と同じ

    // --- %d / %i: 整数 ---
    printf("\n== %%d / %%i（整数）==\n");
    printf("1: [%d]\n", 42);
    printf("2: [%+d]\n", 42);          // 正負記号あり
    printf("3: [%4d]\n", 42);          // 幅4、右寄せ
    printf("4: [%-4d]\n", 42);         // 幅4、左寄せ
    printf("5: [%04d]\n", 42);         // ゼロ埋め
    printf("6: [%.4d]\n", 42);         // 精度4、ゼロ埋め
    printf("7: [%.0d]\n", 0);          // ゼロ省略

    // --- %x: 16進 ---
    printf("\n== %%x（16進）==\n");
    printf("1: [%x]\n", 255);
    printf("2: [%5x]\n", 255);         // 幅5
    printf("3: [%.5x]\n", 255);        // 精度5
    printf("4: [%#x]\n", 255);         // プレフィックス 0x 付き

    // --- %p: ポインタ ---
    printf("\n== %%p（ポインタ）==\n");
    int a = 123;
    printf("1: [%p]\n", (void*)&a);
    printf("2: [%20p]\n", (void*)&a);  // 幅指定（無視されることも）
}

void gpt_op(void)
{
    int i = 42, neg = -42;
    unsigned int u = 42;
    char ch = 'A';
    char *str = "Hello";
    void *ptr = &i;

    printf("== %%c ==\n");
    printf("[%-3c] 左詰め\n", ch);

    printf("\n== %%s ==\n");
    printf("[%-10.3s] 左詰め + 精度\n", str);

    printf("\n== %%p ==\n");
    printf("[%-20p] 左詰め\n", ptr);

    printf("\n== %%d ==\n");
    printf("[%-6d] 左詰め\n", i);
    printf("[%+6d] +符号\n", i);
    printf("[% 6d] blank空白\n", i);
    printf("[%06d] ゼロ埋め\n", i);
    printf("[%.4d] 精度4\n", i);
    printf("[%.4d] 精度4 (負数)\n", neg);

    printf("\n== %%i ==\n");
    // printf("[%+06.4i] +ゼロ精度無視\n", i); // ゼロ埋めは精度指定で無視

    printf("\n== %%u ==\n");
    printf("[%06u] ゼロ埋め\n", u);
    printf("[%.4u] 精度\n", u);
    printf("[%-6u] 左詰め\n", u);

    printf("\n== %%x ==\n");
    printf("[%#x] #付き\n", u);
    printf("[%06x] ゼロ埋め\n", u);
    printf("[%.4x] 精度\n", u);
    printf("[%-6x] 左詰め\n", u);

    printf("\n== %%X ==\n");
    printf("[%#X] #付き\n", u);
    printf("[%06X] ゼロ埋め\n", u);
    printf("[%.4X] 精度\n", u);
    printf("[%-6X] 左詰め\n", u);
}
