# PassCheck-C

Ein **Passwort-Analyzer in C**, der Passwörter anhand ihrer Zeichen und einiger einfacher Regeln untersucht.

## Aktuelle Funktionen

- Zählt Zeichenlänge, Groß- und Kleinbuchstaben, Ziffern und Sonderzeichen.
- Erkennt **mindestens drei gleiche Zeichen hintereinander** (z. B. `aaa`).
- Erkennt **aufsteigende Zeichenfolgen** mit mindestens drei Zeichen (z. B. `abc`, `123`).
- Vergleicht Passwörter mit einer lokalen Liste von **260 Beispiel-Passwörtern**.
- Prüft Mindestanforderungen: **mindestens 9 Zeichen** sowie jeweils mindestens ein Großbuchstabe, Kleinbuchstabe, eine Ziffer und ein Sonderzeichen.
- Zeigt die Analyse im Terminal an.

**Aktueller Stand:** Das Testpasswort ist noch direkt in `main.c` festgelegt. Eine Benutzereingabe gibt es noch nicht. Programm ist noch nicht vollständig

## Geplante Funktionen

- [ ] **Benutzereingabe:** Passwort direkt im Terminal eingeben
- [ ] **Entropie:** geschätzte Passwortentropie in **Bit** berechnen.
- [ ] **Time to Crack:** geschätzte Zeit zum Knacken unter ausdrücklich genannten Annahmen zur Angriffsgeschwindigkeit anzeigen.
- [ ] **Stärkebewertung:** verständliche Bewertung und konkrete Verbesserungsvorschläge ausgeben.

> **Hinweis:** Das Projekt dient Lernzwecken. Eine kurze Passwortliste und einfache Regeln können die tatsächliche Sicherheit nicht zuverlässig bestimmen. Auch Entropie und Knackzeit sind nur Schätzwerte.
