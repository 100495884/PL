int i = 0;

main() {
    while (i <= 5) {
        printf("%d\n", i);
        if ((i % 2) == 0) {
            puts("i es par");
        } else {
            puts("i es impar");
        }
        i = i + 1;
    }
}
//@(main)
