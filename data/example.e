var t0
f_maxSubArray [2]
var t2
var t1
var t3
var t5
var t4
var t8
var t7
var t6
var T0
var t11
var t10
var t9
var T1
var T2
var t12
var t13
var t15
var t14
var t16
var t19
var t18
var t17
var t20
var t22
var t21
t1 = 0
t2 = p1 == t1
if t2 == 0 goto l0
t3 = 0
return t3
l0:
t4 = 1
t5 = p1 == t4
if t5 == 0 goto l1
t6 = 0
t7 = t6
t7 = t7 * 4
t8 = p0[t7]
return t8
l1:
t9 = 0
t10 = t9
t10 = t10 * 4
t11 = p0[t10]
T0 = t11
T1 = T0
t12 = 1
T2 = t12
l2:
t13 = T2 < p1
if t13 == 0 goto l3
t14 = 0
t15 = T0 < t14
if t15 == 0 goto l4
t16 = 0
T0 = t16
l4:
t17 = T2
t17 = t17 * 4
t18 = p0[t17]
t19 = T0 + t18
T0 = t19
t20 = T1 < T0
if t20 == 0 goto l5
T1 = T0
l5:
t21 = 1
t22 = T2 + t21
T2 = t22
goto l2
l3:
return T1
return 0
end f_maxSubArray
f_main [0]
var T3
var 40 T4
var t25
var t24
var t23
var t27
var t26
var t30
var t29
var t28
var t31
var t34
var t33
var t32
var t35
var t38
var t37
var t36
var t40
var t39
var t43
var t42
var t41
var t44
var t47
var t46
var t45
var t48
var t51
var t50
var t49
var t53
var t52
var t56
var t55
var t54
var t57
var t60
var t59
var t58
var t61
var t64
var t63
var t62
var t65
var t66
var t67
t23 = 0
t24 = t23
t24 = t24 * 4
t25 = T4 + t24
t26 = 4
t27 = -t26
t25[0] = t27
t28 = 1
t29 = t28
t29 = t29 * 4
t30 = T4 + t29
t31 = 3
t30[0] = t31
t32 = 2
t33 = t32
t33 = t33 * 4
t34 = T4 + t33
t35 = 9
t34[0] = t35
t36 = 3
t37 = t36
t37 = t37 * 4
t38 = T4 + t37
t39 = 2
t40 = -t39
t38[0] = t40
t41 = 4
t42 = t41
t42 = t42 * 4
t43 = T4 + t42
t44 = 0
t43[0] = t44
t45 = 5
t46 = t45
t46 = t46 * 4
t47 = T4 + t46
t48 = 1
t47[0] = t48
t49 = 6
t50 = t49
t50 = t50 * 4
t51 = T4 + t50
t52 = 6
t53 = -t52
t51[0] = t53
t54 = 7
t55 = t54
t55 = t55 * 4
t56 = T4 + t55
t57 = 5
t56[0] = t57
t58 = 8
t59 = t58
t59 = t59 * 4
t60 = T4 + t59
t61 = 7
t60[0] = t61
t62 = 9
t63 = t62
t63 = t63 * 4
t64 = T4 + t63
t65 = 8
t64[0] = t65
t66 = 10
T3 = t66
param T4
param T3
t67 = call f_maxSubArray
T3 = t67
return T3
return 0
end f_main
