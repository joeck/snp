# 5.4 Aufgabe: Refactoring der Synchronisation

## a)

Es kann passieren, dass eine Überweisung auf halber Strecke verloren geht. Somit wäre bei einem Transfer von Bank A zu Bank B bei A das Geld schon abgezogen aber bei B nicht hinzugefügt.

## b)

Es müssen branchLocks verwendet werden.

## c)

Variante 5.2 ist performanter. Variante 5.3 ist nicht sehr sinvoll. Variante 5.4 ist IBC Konform und das zu empfehlende auch wenn nicht es nicht die beste Performance hat.