var t0
var 100 T0
var t1
var t2
var t3
var t4
var t5
var t6
var t7
var t8
var t9
var t10
var t11
var t12
var t13
var t14
var t15
f_add [1]
var t18
var t17
var t16
var t23
var t21
var t20
var t19
var t22
var t26
var t25
var t24
var t31
var t29
var t28
var t27
var t30
var t34
var t33
var t32
var t39
var t37
var t36
var t35
var t38
t16 = 0
t17 = t16
t17 = t17 * 4
t18 = p0 + t17
t19 = 0
t20 = t19
t20 = t20 * 4
t21 = p0[t20]
t22 = 1
t23 = t21 + t22
t18[0] = t23
t24 = 1
t25 = t24
t25 = t25 * 4
t26 = p0 + t25
t27 = 1
t28 = t27
t28 = t28 * 4
t29 = p0[t28]
t30 = 1
t31 = t29 + t30
t26[0] = t31
t32 = 2
t33 = t32
t33 = t33 * 4
t34 = p0 + t33
t35 = 2
t36 = t35
t36 = t36 * 4
t37 = p0[t36]
t38 = 1
t39 = t37 + t38
t34[0] = t39
return
end f_add
f_main [0]
var t42
var t41
var t40
var t45
var t44
var t43
var t46
var t47
t1 = 1
T0[0] = t1
t2 = 2
T0[4] = t2
t3 = 3
T0[8] = t3
t4 = 4
T0[12] = t4
t5 = 5
T0[16] = t5
t6 = 6
T0[20] = t6
t7 = 7
T0[24] = t7
t8 = 8
T0[28] = t8
t9 = 9
T0[32] = t9
t10 = 10
T0[36] = t10
t11 = 11
T0[40] = t11
t12 = 12
T0[44] = t12
t13 = 13
T0[48] = t13
t14 = 14
T0[52] = t14
t15 = 15
T0[56] = t15
t40 = 1
t41 = t40
t41 = t41 * 5
t41 = t41 * 4
t42 = T0 + t41
param t42
call f_add
t43 = 4
t44 = t43
t44 = t44 * 5
t44 = t44 * 4
t45 = T0 + t44
param t45
call f_add
t46 = 25
param t46
param T0
call f_putarray
t47 = 0
return t47
return 0
end f_main
