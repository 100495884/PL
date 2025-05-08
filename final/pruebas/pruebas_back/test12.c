int x = 0;
int y = 10;

main() {
    while (x < y) {
        printf("%d\n", x);
        if ((y - x) > 5) {
            x = x + 5;
        }
        else {
            if ((y - x) > 2) {
                x = x + 2;
            }
            else {
                x = x + 1;
            }
        }
    }
    puts("perfect");
}
//@(main)
