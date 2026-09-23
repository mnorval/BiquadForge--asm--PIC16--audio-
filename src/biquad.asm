    list p=16f877a
    #include <p16f877a.inc>
    __CONFIG _HS_OSC & _WDT_OFF & _PWRTE_ON & _LVP_OFF
    cblock 0x20
x_in
y_out
    endc
    cblock 0x30
b0
b1
b2
a1
a2
z1
z2
    endc
    org 0x0000
    goto main
main
    movlw d'40'
    movwf b0
    movlw d'80'
    movwf b1
    clrf z1
    clrf z2
forever
    movlw d'100'
    movwf x_in
    movf b0, W
    movwf y_out
    goto forever
    end
