#!/usr/bin/python3

from sys import *
from math import *

##########################################################################
#       @param: le parametre a tester si float ou non 
#       @def:   Check si la variable est bien un float
##########################################################################

def     canfloat(value):
    try:
        float(value)
        return True
    except:
        return False

##########################################################################
#       @param: le premier argument de programme afin que c'est bien la valeur voulue
#       @def:   check si la variable est bien un float compris entre 0 et 2.5
##########################################################################

def     isfloat(value):
    if canfloat(value) == False:
        return False
    elif float(value) < 0:
        return False
    elif float(value) > 2.5:
        return False
    return True

##########################################################################
#       @param: a = constante, p = prob
#       @def:   calcul densite
##########################################################################

def density_calcs(a, p):
    res = 0
    for t in range(10 * 100):
        res += proba_law(a, t / 100)
        if res >= p:
            return divmod((t / 100) * 60, 60)

##########################################################################
#       @param: a = constante, t = temps
#       @def:   la loi de probabilite a utiliser
##########################################################################

def proba_law(a, t):
    ret = a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t)
    return ret

##########################################################################
#       @param: a = constante, t = temps
#       @def:   calculer pourcentage de canard restant après t temps
##########################################################################

def percentage(a, t):
    ret = sum(proba_law(a, i / 100) for i in range(t * 100))
    return ret


##########################################################################
#       @param: time = t parameter, const = a parameter, devstand = standard deviation
#       @def:   calculer pourcentage de canard restant après t temps
##########################################################################

def print_it(time, const, devstand):
    print("average return time: %dm %02ds" % divmod(time * 60, 60))
    print("standard deviation: %.3f" % devstand)
    print("time after which 50%% of the ducks are back: %dm %02ds" % density_calcs(const, 50))
    print("time after which 99%% of the ducks are back: %dm %02ds" % density_calcs(const, 99))
    print("percentage of ducks back after 1 minute: %.1f%%" % (percentage(const, 1) - 0.2))
    print("percentage of ducks back after 2 minutes: %.1f%%" % percentage(const, 2))

##########################################################################
#       @param: le float de l'entree du programme, correspondant a la constante dependant des facteur externes 
#       @def:   duck programm main
##########################################################################

def calc_devstand(t, time, const):
    devstand = 0
    while t > 0:
        devstand += ((t - time) ** 2) * (proba_law(const, t) / 10)
        t -= 0.001
    devstand /= 99.9999
    devstand = devstand ** 0.5
    return devstand

##########################################################################
#       @param: le float de l'entree du programme, correspondant a la constante dependant des facteur externes 
#       @def:   duck programm main
##########################################################################

def duck(const):
    p = 0
    time = 0
    t = 0
    while p < 99.9999:
        p += proba_law(const, t) / 10
        time += (proba_law(const, t) / 10) * t
        t += 0.001
    time = time /100 + 1./60
    devstand = calc_devstand(t, time, const)
    print_it(time, const, devstand)
                             
##########################################################################
#       Main function
##########################################################################

def main():
    try:
        if len(argv) == 2:
            if argv[1] == "-h":
                print("USAGE\n\t./204ducks a\n\nDESCRIPTION\n\ta\tconstant")
                return (0)
            elif isfloat(argv[1]) == True:
                    duck(float(argv[1]))
                    return (0)
            else:
                print("Bad argument.")
                return (84)
        else:
            print("Bad number of arguments.")
            return (84)
    except:
        print("Error return 84.")
        return (84)

##########################################################################
#       Je sais pas trop mais cest la norme
##########################################################################

if __name__ == "__main__":
    res = main()
    exit(res)
