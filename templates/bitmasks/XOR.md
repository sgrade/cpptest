# XOR

Commutativity: aXORb=bXORa
The order in which you XOR two numbers doesn’t matter.

Associativity: (aXORb)XORc=aXOR(bXORc)
Grouping of XOR operations doesn’t affect the result.

Identity: aXOR0=a
XOR with 0 leaves the number unchanged.

Self-inverse: aXORa=0
XORing a number with itself results in 0.

Inversion:
If aXORb=c, then:

a=bXORc
b=aXORc

Source - https://leetcode.com/problems/neighboring-bitwise-xor/editorial/
