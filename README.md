# semesterarbeit_cpp2_nowakiewicz
Diese Semesterarbeit wurde für den Kurs "C++ - Programmieren 2" erstellt und beinhaltet die Oberfläche eines Spiels, bei
welchem der Spieler einen Avatar steuern kann und Objekten ausweichen kann. Die Steuerung funktioniert entweder durch die Pfeiltasten
am Computer oder durch das Klicken der linken und rechten Maustaste. Ein Punktecounter in der linken oberen Ecke zeigt den Punktestand
an, welcher stetig ansteigt und drei rot ausgefüllte Kreise in der rechten oberen Ecke stellen das Leben des Spielers dar. Die Objekte 
gehören jeweils einer Klasse an, die sich in Geschwindigkeit, Form und Farbe unterscheiden. 
Die Buttons Start/Pause, Beenden, Sichern und Laden ermöglichen dem Spieler das Starten und Pausieren des Spiels (der Button ändert
seine Beschriftung), das Beenden des Spiels, das Sichern des Speicherstandes und das Laden des Speicherstandes. Empfohlen wird
das Spiel erst zu speichern, während man es pausiert hat. Weitere Kommentare zu Funktionen lassen sich in den Dateien finden!

Die Dateien main.cpp, meinwidget.cpp und zeichenfeld.cpp setzen die Arbeit zusammen. Die main-Datei beinhaltet das Anzeigen des Programms.
Die meinwidget-Datei beinhaltet die Oberfläche des Programms und wo genau die Buttons und die Zeichenfläche platziert werden sollen. Sie
beinhaltet ebenso die Methoden start(), saveFile() und loadFile() und die Steuerung durch die Pfeiltasten. Die zeichenfeld-Datei 
beinhaltet alle Objekte, welche in dem Zeichenfeld zu sehen sind. 

Für diese Semesterarbeit wurde Stufe 1 und ein Teil von Stufe 2 erledigt!
