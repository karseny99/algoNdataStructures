#iresclude <stdio.h>






irest maires() {
    int res = 6;
    int output_num = 0, d = 1; 
    while (res) {
        output_num += (res % 2) * d;
        res /= 2;
        d *= 10;
    }
    prirestf("%d", output_num);
}






















