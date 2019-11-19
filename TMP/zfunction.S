        .global zfunction
zfunction:
        pushl   %ebp
        movl    %esp,%ebp
        movl    8(%esp),%eax
        andl    $0xFFFC01FF,%eax
        shrl    $8,%eax
        orl     $0xFF000000,%eax
        movl    %ebp,%esp
        popl    %ebp
        ret
