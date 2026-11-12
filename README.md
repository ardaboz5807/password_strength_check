# PassCheck-C

Ein **Passwort-Analyzer in C**, der Passwörter anhand ihrer Zeichen, Muster und verschiedener Sicherheitskriterien untersucht.

Das Programm ist funktionsfähig, befindet sich jedoch weiterhin in der Entwicklung.

## Funktionen

- Zählt Passwortlänge, Groß- und Kleinbuchstaben, Ziffern und Sonderzeichen.
- Erkennt **mindestens drei gleiche Zeichen hintereinander** (z. B. `aaa`).
- Erkennt **aufsteigende Zeichenfolgen** mit mindestens drei Zeichen (z. B. `abc`, `123`).
- Vergleicht Passwörter mit einer lokalen Liste von **260 Beispiel-Passwörtern**.
- Prüft Mindestanforderungen: **mindestens 9 Zeichen** sowie jeweils mindestens ein Großbuchstabe, Kleinbuchstabe, eine Ziffer und ein Sonderzeichen.
- Ermöglicht die **Passworteingabe direkt im Terminal**.
- Berechnet die **theoretische Passwort-Entropie in Bits**.
- Schätzt die **Brute-Force-Knackzeit** bei angenommenen 10 Milliarden Versuchen pro Sekunde.
- Warnt bei häufig verwendeten Passwörtern aus der lokalen Liste.
- Zeigt alle Analyseergebnisse übersichtlich im Terminal an.

## Installation und Ausführung

GCC wird zum Kompilieren benötigt.

Im Hauptverzeichnis des Projekts:

```bash
gcc src/main.c src/analyzer.c -o passcheck.exe -lm
```

Anschließend unter Windows ausführen:

```powershell
.\passcheck.exe
```

Die Datei `data/common_passwords.txt` muss vom Arbeitsverzeichnis aus erreichbar sein.

## Hinweis

Dieses Projekt dient Lernzwecken. Die Passwortanalyse kann die tatsächliche Sicherheit eines Passworts nicht zuverlässig bestimmen. Entropie und Crack Time basieren auf einem theoretischen Zufallsmodell und stellen keine Sicherheitsgarantie dar.