code = input()
code = code.split(' ')

var= []
for j in range(100):
    var.append(0)

while True:
    if var[89]+1 > len(code):
        break
    
    var[89] += 1

    ccode = code[var[89]-1]

    op1 = ccode[:2]
    op2 = ccode[2:]

    if op1=='90':
        var[90] = int(op2)
    elif op1=='89':
        var[89] = int(op2)
    elif op1=='88':
        if var[84]>var[83]:
            var[89]=int(op2)
        else:
            pass
    elif op1=='86' and op2!='87':
        var[86] = var[var[int(op2)]]
    elif op2=='87' and op1!='86':
        var[var[int(op1)]] = var[87]
    elif op1 == '97':
        print(var[int(op2)])
    elif op2=='98':
        num = int(input())
        var[int(op1)]=num
    else:
        var[int(op1)]=var[int(op2)]

    var[93] = var[92]+var[91]
    var[94] = var[91]-var[92]
    var[95] = var[92]*var[91]
    if var[92]!=0:
        var[96] = var[91]//var[92]