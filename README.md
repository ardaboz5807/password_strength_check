# PassCheck-C

Ein schlanker **Passwort-Analyzer in C**, der Passwörter anhand ihrer Zeichen und einiger einfacher Regeln untersucht.

## Aktuelle Funktionen

- Zählt Zeichenlänge, Groß- und Kleinbuchstaben, Ziffern und Sonderzeichen.
- Erkennt **mindestens drei gleiche Zeichen hintereinander** (z. B. `aaa`).
- Erkennt **aufsteigende Zeichenfolgen** mit mindestens drei Zeichen (z. B. `abc`, `123`).
- Vergleicht Passwörter mit einer lokalen Liste von **260 Beispiel-Passwörtern**.
- Prüft Mindestanforderungen: **mindestens 9 Zeichen** sowie jeweils mindestens ein Großbuchstabe, Kleinbuchstabe, eine Ziffer und ein Sonderzeichen.
- Zeigt die Analyse im Terminal an.

## Kompilieren und starten

Im Projektverzeichnis (wenn `main.c` und `analyzer.c` dort liegen):

```bash
gcc -std=c11 -Wall -Wextra main.c analyzer.c -o passcheck
./passcheck
```

Unter Windows: `passcheck.exe` starten. Die Datei `data/common_passwords.txt` muss relativ zum aktuellen Arbeitsverzeichnis erreichbar sein.

**Aktueller Stand:** Das Testpasswort ist noch direkt in `main.c` festgelegt. Eine Benutzereingabe gibt es noch nicht.

## Geplante Funktionen

- [ ] **Benutzereingabe:** Passwort direkt im Terminal eingeben, möglichst verdeckt.
- [ ] **Entropie:** geschätzte Passwortentropie in **Bit** berechnen.
- [ ] **Time to Crack:** geschätzte Zeit zum Knacken unter ausdrücklich genannten Annahmen zur Angriffsgeschwindigkeit anzeigen.
- [ ] **Stärkebewertung:** verständliche Bewertung und konkrete Verbesserungsvorschläge ausgeben.

> **Hinweis:** Das Projekt dient Lernzwecken. Eine kurze Passwortliste und einfache Regeln können die tatsächliche Sicherheit nicht zuverlässig bestimmen. Auch Entropie und Knackzeit sind nur Schätzwerte.
