v0 = 0
v1 = 0
f_counting_sort [3] [89]
store s0 77
store s1 78
store s2 79
store s3 80
store s4 81
store s5 82
store s6 83
store s7 84
store s8 85
store s9 86
store s10 87
store s11 88
t2 = 0
store t2 66
load 66 t0
s9 = t0
t2 = 0
store t2 65
load 65 t0
s11 = t0
t2 = 0
store t2 64
load 64 t0
s10 = t0
l0:
t2 = 10
store t2 62
load 62 t1
t2 = s9 < t1
store t2 63
load 63 t0
t1 = 0
if t0 == t1 goto l1
s8 = s9
s8 = s8 * 4
loadaddr 67 t0
t2 = t0 + s8
store t2 61
t2 = 0
store t2 60
load 60 t0
load 61 t6
t6[0] = t0
t2 = 1
store t2 58
load 58 t1
t2 = s9 + t1
store t2 59
load 59 t0
s9 = t0
goto l0
l1:
l2:
t2 = s11 < a2
store t2 57
load 57 t0
t1 = 0
if t0 == t1 goto l3
t2 = s11
store t2 54
load 54 t0
t2 = t0 * 4
store t2 54
load 54 t6
t5 = a0
t1 = t6 + t5
t2 = t1[0]
store t2 55
load 55 t0
s7 = t0
s7 = s7 * 4
loadaddr 67 t0
t2 = t0 + s7
store t2 56
t2 = s11
store t2 49
load 49 t0
t2 = t0 * 4
store t2 49
load 49 t6
t5 = a0
t1 = t6 + t5
t2 = t1[0]
store t2 50
load 50 t0
t2 = t0
store t2 51
load 51 t0
t2 = t0 * 4
store t2 51
load 51 t6
loadaddr 67 t5
t1 = t6 + t5
t2 = t1[0]
store t2 52
t2 = 1
store t2 48
load 52 t0
load 48 t1
t2 = t0 + t1
store t2 53
load 53 t0
load 56 t6
t6[0] = t0
t2 = 1
store t2 46
load 46 t1
t2 = s11 + t1
store t2 47
load 47 t0
s11 = t0
goto l2
l3:
t2 = 1
store t2 45
load 45 t0
s9 = t0
l4:
t2 = 10
store t2 43
load 43 t1
t2 = s9 < t1
store t2 44
load 44 t0
t1 = 0
if t0 == t1 goto l5
s6 = s9
s6 = s6 * 4
loadaddr 67 t0
t2 = t0 + s6
store t2 42
t2 = s9
store t2 39
load 39 t0
t2 = t0 * 4
store t2 39
load 39 t6
loadaddr 67 t5
t1 = t6 + t5
t2 = t1[0]
store t2 40
t2 = 1
store t2 35
load 35 t1
t2 = s9 - t1
store t2 36
load 36 t0
t2 = t0
store t2 37
load 37 t0
t2 = t0 * 4
store t2 37
load 37 t6
loadaddr 67 t5
t1 = t6 + t5
t2 = t1[0]
store t2 38
load 40 t0
load 38 t1
t2 = t0 + t1
store t2 41
load 41 t0
load 42 t6
t6[0] = t0
t2 = 1
store t2 33
load 33 t1
t2 = s9 + t1
store t2 34
load 34 t0
s9 = t0
goto l4
l5:
s10 = a2
l6:
t2 = 0
store t2 31
load 31 t1
t2 = s10 > t1
store t2 32
load 32 t0
t1 = 0
if t0 == t1 goto l7
t2 = 1
store t2 26
load 26 t1
t2 = s10 - t1
store t2 27
load 27 t0
t2 = t0
store t2 28
load 28 t0
t2 = t0 * 4
store t2 28
load 28 t6
t5 = a0
t1 = t6 + t5
t2 = t1[0]
store t2 29
load 29 t0
s5 = t0
s5 = s5 * 4
loadaddr 67 t0
t2 = t0 + s5
store t2 30
t2 = 1
store t2 20
load 20 t1
t2 = s10 - t1
store t2 21
load 21 t0
s4 = t0
s4 = s4 * 4
t5 = a0
t1 = s4 + t5
t2 = t1[0]
store t2 22
load 22 t0
t2 = t0
store t2 23
load 23 t0
t2 = t0 * 4
store t2 23
load 23 t6
loadaddr 67 t5
t1 = t6 + t5
t2 = t1[0]
store t2 24
t2 = 1
store t2 19
load 24 t0
load 19 t1
t2 = t0 - t1
store t2 25
load 25 t0
load 30 t6
t6[0] = t0
t2 = 1
store t2 14
load 14 t1
t2 = s10 - t1
store t2 15
load 15 t0
s1 = t0
s1 = s1 * 4
t5 = a0
t1 = s1 + t5
t2 = t1[0]
store t2 16
load 16 t0
s2 = t0
s2 = s2 * 4
loadaddr 67 t5
t1 = s2 + t5
t2 = t1[0]
store t2 17
load 17 t0
s3 = t0
s3 = s3 * 4
t2 = a1 + s3
store t2 18
t2 = 1
store t2 11
load 11 t1
t2 = s10 - t1
store t2 12
load 12 t0
s0 = t0
s0 = s0 * 4
t5 = a0
t1 = s0 + t5
t2 = t1[0]
store t2 13
load 13 t0
load 18 t6
t6[0] = t0
t2 = 1
store t2 9
load 9 t1
t2 = s10 - t1
store t2 10
load 10 t0
s10 = t0
goto l6
l7:
t2 = 0
store t2 8
load 8 a0
load 77 s0
load 78 s1
load 79 s2
load 80 s3
load 81 s4
load 82 s5
load 83 s6
load 84 s7
load 85 s8
load 86 s9
load 87 s10
load 88 s11
return
a0 = 0
load 77 s0
load 78 s1
load 79 s2
load 80 s3
load 81 s4
load 82 s5
load 83 s6
load 84 s7
load 85 s8
load 86 s9
load 87 s10
load 88 s11
return
end f_counting_sort
f_main [0] [80]
store s0 68
store s1 69
store s2 70
store s3 71
store s4 72
store s5 73
store s6 74
store s7 75
store s8 76
store s9 77
store s10 78
store s11 79
t2 = 10
store t2 67
load 67 t0
t2 = t0
loadaddr v0 t6
t6[0] = t2
t2 = 0
store t2 55
load 55 t0
s11 = t0
s11 = s11 * 4
loadaddr 57 t0
t2 = t0 + s11
store t2 56
t2 = 4
store t2 54
load 54 t0
load 56 t6
t6[0] = t0
t2 = 1
store t2 52
load 52 t0
s10 = t0
s10 = s10 * 4
loadaddr 57 t0
t2 = t0 + s10
store t2 53
t2 = 3
store t2 51
load 51 t0
load 53 t6
t6[0] = t0
t2 = 2
store t2 49
load 49 t0
s9 = t0
s9 = s9 * 4
loadaddr 57 t0
t2 = t0 + s9
store t2 50
t2 = 9
store t2 48
load 48 t0
load 50 t6
t6[0] = t0
t2 = 3
store t2 46
load 46 t0
s8 = t0
s8 = s8 * 4
loadaddr 57 t0
t2 = t0 + s8
store t2 47
t2 = 2
store t2 45
load 45 t0
load 47 t6
t6[0] = t0
t2 = 4
store t2 43
load 43 t0
s7 = t0
s7 = s7 * 4
loadaddr 57 t0
t2 = t0 + s7
store t2 44
t2 = 0
store t2 42
load 42 t0
load 44 t6
t6[0] = t0
t2 = 5
store t2 40
load 40 t0
s6 = t0
s6 = s6 * 4
loadaddr 57 t0
t2 = t0 + s6
store t2 41
t2 = 1
store t2 39
load 39 t0
load 41 t6
t6[0] = t0
t2 = 6
store t2 37
load 37 t0
s5 = t0
s5 = s5 * 4
loadaddr 57 t0
t2 = t0 + s5
store t2 38
t2 = 6
store t2 36
load 36 t0
load 38 t6
t6[0] = t0
t2 = 7
store t2 34
load 34 t0
s4 = t0
s4 = s4 * 4
loadaddr 57 t0
t2 = t0 + s4
store t2 35
t2 = 5
store t2 33
load 33 t0
load 35 t6
t6[0] = t0
t2 = 8
store t2 31
load 31 t0
s3 = t0
s3 = s3 * 4
loadaddr 57 t0
t2 = t0 + s3
store t2 32
t2 = 7
store t2 30
load 30 t0
load 32 t6
t6[0] = t0
t2 = 9
store t2 28
load 28 t0
s2 = t0
s2 = s2 * 4
loadaddr 57 t0
t2 = t0 + s2
store t2 29
t2 = 8
store t2 27
load 27 t0
load 29 t6
t6[0] = t0
t2 = 0
store t2 26
load 26 t0
s1 = t0
store a0 0
loadaddr 57 a0
store a1 1
loadaddr 16 a1
store a2 2
load v0 a2
call f_counting_sort
store a0 15
load 15 t0
s1 = t0
l8:
load v0 t1
t2 = s1 < t1
store t2 14
load 14 t0
t1 = 0
if t0 == t1 goto l9
t2 = s1
store t2 12
load 12 t0
t2 = t0 * 4
store t2 12
load 12 t6
loadaddr 16 t5
t1 = t6 + t5
t2 = t1[0]
store t2 13
load 13 t0
s0 = t0
store a0 0
a0 = s0
call f_putint
t2 = 10
store t2 11
load 11 t0
s0 = t0
store a0 0
a0 = s0
call f_putch
t2 = 1
store t2 9
load 9 t1
t2 = s1 + t1
store t2 10
load 10 t0
s1 = t0
goto l8
l9:
t2 = 0
store t2 8
load 8 a0
load 68 s0
load 69 s1
load 70 s2
load 71 s3
load 72 s4
load 73 s5
load 74 s6
load 75 s7
load 76 s8
load 77 s9
load 78 s10
load 79 s11
return
a0 = 0
load 68 s0
load 69 s1
load 70 s2
load 71 s3
load 72 s4
load 73 s5
load 74 s6
load 75 s7
load 76 s8
load 77 s9
load 78 s10
load 79 s11
return
end f_main
