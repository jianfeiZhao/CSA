# 测试用例 1-5 

#### 包含的指令
- [x] ADDU
- [ ] SUBU
- [x] LW
- [x] SW
- [ ] BEQ

#### 采分点
- [x] RAW hazards
- [ ] BEQ

#### 汇编指令
```
LW    R1, R0, 0
LW    R2, R0, 4
ADDU  R3, R1, R2
ADDU  R4, R3, R2
ADDU  R5, R3, R4
LW    R6, R0, 8
ADDU  R7, R6, R5
SW    R7, R0, 12
LW    R8, R0, 4
SW    R8, R0, 16
HALT
```