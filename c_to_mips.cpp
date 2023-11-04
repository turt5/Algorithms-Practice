int superFunc(int array[], int size, int k){
    int x = k, sum = 0, mul = 1;
    while(x<size-1){
        int j = array[x + 1];
        while(j!=array[x]){
            mul *= 5;
            j--;
        }

        sum += (mul + j);
        array[x - 1] = sum;
        x += 2;
    }

    if(sum<mul){
        return sum;
    }else{
        return sum + mul;
    }
}

/////ANSWER:::::

/*

x=$s0
sum=$s1
mul=$s2
array[]=$a0
size=$a1
k=$a2


addi $sp,$sp, -12

sw $s0, 8($sp)
sw $s1 4($sp)
sw $s2 0($sp)


add $s0, $a2, $zero
addi $s1, $zero, 0
addi $s2, $zero, 1

addi $t0, $a1, -1

MAIN_WHILE:
slt $t1, $s0, $t0
beq $t1, $zero EXIT_MAIN_WHILE

addi $t2, $s0, 1
sll $t3, $t2, 2
lw $t4, $t3($a0)
add $s3, $t4, $zero

sll $t5, $s0, 2
lw $t6, $t5($a0)
bne $s3, $t6, INNER_WHILE

add $t7, $s2, $s3
add $s1, $s1, $t7

INNER_WHILE:
addi $t6, $t6, -1
mul $s2, $s2, 5
bne $t6, $s3, INNER_WHILE

j MAIN_WHILE

EXIT_MAIN_WHILE:
slt $t1, $s1, $s2
beq $t1, $zero SUM_GREATER_THAN_MUL

jr $ra

SUM_GREATER_THAN_MUL:
add $v0, $s1, $s2
jr $ra




*/
