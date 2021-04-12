var t0
var T0
f_counting_sort [3]
var 40 T1
var T2
var T3
var T4
var t1
var t2
var t3
var t5
var t4
var t7
var t6
var t8
var t10
var t9
var t11
var t15
var t14
var t13
var t12
var t21
var t19
var t18
var t17
var t16
var t20
var t23
var t22
var t24
var t26
var t25
var t28
var t27
var t35
var t30
var t29
var t34
var t33
var t32
var t31
var t37
var t36
var t39
var t38
var t45
var t44
var t43
var t42
var t41
var t40
var t53
var t51
var t50
var t49
var t48
var t47
var t46
var t52
var t61
var t60
var t59
var t58
var t57
var t56
var t55
var t54
var t65
var t64
var t63
var t62
var t67
var t66
var t68
t1 = 0
T4 = t1
t2 = 0
T2 = t2
t3 = 0
T3 = t3
l0:
t4 = 10
t5 = T4 < t4
if t5 == 0 goto l1
t6 = T4
t6 = t6 * 4
t7 = T1 + t6
t8 = 0
t7[0] = t8
t9 = 1
t10 = T4 + t9
T4 = t10
goto l0
l1:
l2:
t11 = T2 < p2
if t11 == 0 goto l3
t12 = T2
t12 = t12 * 4
t13 = p0[t12]
t14 = t13
t14 = t14 * 4
t15 = T1 + t14
t16 = T2
t16 = t16 * 4
t17 = p0[t16]
t18 = t17
t18 = t18 * 4
t19 = T1[t18]
t20 = 1
t21 = t19 + t20
t15[0] = t21
t22 = 1
t23 = T2 + t22
T2 = t23
goto l2
l3:
t24 = 1
T4 = t24
l4:
t25 = 10
t26 = T4 < t25
if t26 == 0 goto l5
t27 = T4
t27 = t27 * 4
t28 = T1 + t27
t29 = T4
t29 = t29 * 4
t30 = T1[t29]
t31 = 1
t32 = T4 - t31
t33 = t32
t33 = t33 * 4
t34 = T1[t33]
t35 = t30 + t34
t28[0] = t35
t36 = 1
t37 = T4 + t36
T4 = t37
goto l4
l5:
T3 = p2
l6:
t38 = 0
t39 = T3 > t38
if t39 == 0 goto l7
t40 = 1
t41 = T3 - t40
t42 = t41
t42 = t42 * 4
t43 = p0[t42]
t44 = t43
t44 = t44 * 4
t45 = T1 + t44
t46 = 1
t47 = T3 - t46
t48 = t47
t48 = t48 * 4
t49 = p0[t48]
t50 = t49
t50 = t50 * 4
t51 = T1[t50]
t52 = 1
t53 = t51 - t52
t45[0] = t53
t54 = 1
t55 = T3 - t54
t56 = t55
t56 = t56 * 4
t57 = p0[t56]
t58 = t57
t58 = t58 * 4
t59 = T1[t58]
t60 = t59
t60 = t60 * 4
t61 = p1 + t60
t62 = 1
t63 = T3 - t62
t64 = t63
t64 = t64 * 4
t65 = p0[t64]
t61[0] = t65
t66 = 1
t67 = T3 - t66
T3 = t67
goto l6
l7:
t68 = 0
return t68
return 0
end f_counting_sort
f_main [0]
var t69
var 40 T5
var t72
var t71
var t70
var t73
var t76
var t75
var t74
var t77
var t80
var t79
var t78
var t81
var t84
var t83
var t82
var t85
var t88
var t87
var t86
var t89
var t92
var t91
var t90
var t93
var t96
var t95
var t94
var t97
var t100
var t99
var t98
var t101
var t104
var t103
var t102
var t105
var t108
var t107
var t106
var t109
var T6
var t110
var 40 T7
var t111
var t112
var T8
var t114
var t113
var t115
var t117
var t116
var t118
t69 = 10
T0 = t69
t70 = 0
t71 = t70
t71 = t71 * 4
t72 = T5 + t71
t73 = 4
t72[0] = t73
t74 = 1
t75 = t74
t75 = t75 * 4
t76 = T5 + t75
t77 = 3
t76[0] = t77
t78 = 2
t79 = t78
t79 = t79 * 4
t80 = T5 + t79
t81 = 9
t80[0] = t81
t82 = 3
t83 = t82
t83 = t83 * 4
t84 = T5 + t83
t85 = 2
t84[0] = t85
t86 = 4
t87 = t86
t87 = t87 * 4
t88 = T5 + t87
t89 = 0
t88[0] = t89
t90 = 5
t91 = t90
t91 = t91 * 4
t92 = T5 + t91
t93 = 1
t92[0] = t93
t94 = 6
t95 = t94
t95 = t95 * 4
t96 = T5 + t95
t97 = 6
t96[0] = t97
t98 = 7
t99 = t98
t99 = t99 * 4
t100 = T5 + t99
t101 = 5
t100[0] = t101
t102 = 8
t103 = t102
t103 = t103 * 4
t104 = T5 + t103
t105 = 7
t104[0] = t105
t106 = 9
t107 = t106
t107 = t107 * 4
t108 = T5 + t107
t109 = 8
t108[0] = t109
t110 = 0
T6 = t110
param T5
param T7
param T0
t111 = call f_counting_sort
T6 = t111
l8:
t112 = T6 < T0
if t112 == 0 goto l9
t113 = T6
t113 = t113 * 4
t114 = T7[t113]
T8 = t114
param T8
call f_putint
t115 = 10
T8 = t115
param T8
call f_putch
t116 = 1
t117 = T6 + t116
T6 = t117
goto l8
l9:
t118 = 0
return t118
return 0
end f_main
