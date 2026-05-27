# Studentų pažymių skaičiavimo programa

## Apie programą

Ši programa skirta studentų duomenims apdoroti.

Programa gali nuskaityti studentų vardus, pavardes, namų darbų pažymius ir egzamino rezultatą. Pagal šiuos duomenis yra apskaičiuojamas galutinis balas.

Galutinis balas gali būti skaičiuojamas pagal:

- namų darbų vidurkį;
- namų darbų medianą.

---

## Programos funkcijos

Programa leidžia:

- rankiniu būdu įvesti studentų duomenis;
- generuoti pažymius;
- generuoti studentus ir jų pažymius;
- nuskaityti studentų duomenis iš failo;
- generuoti studentų failus;
- skaičiuoti galutinį balą pagal vidurkį arba medianą;
- rūšiuoti studentus pagal vardą, pavardę arba rezultatą;
- skirstyti studentus į dvi grupes;
- atlikti veikimo spartos tyrimus;
- testuoti `Studentas` klasę;
- peržiūrėti sugeneruotą Doxygen dokumentaciją.

---

## Reikalavimai

Norint paleisti programą, reikia turėti:

- C++ kompiliatorių su C++17 palaikymu;
- CMake;
- Git;
- Visual Studio, jeigu norima paleisti unit testus per `Test Explorer`.

---

## Programos atsisiuntimas

Projektą galima atsisiųsti iš GitHub:

```bash
git clone https://github.com/Boljerr/OOP_2.git
cd OOP_2
```

---

## Programos kompiliavimas su CMake

Projektas kompiliuojamas naudojant CMake.

Pirmiausia reikia sukurti `build` aplanką:

```bash
mkdir build
cd build
```

Tada paleisti CMake:

```bash
cmake ..
```

Kompiliavimas `Release` režimu:

```bash
cmake --build . --config Release
```

## Programos paleidimas


```bash
.\Release\Studentai.exe
```

---

## Programos meniu

```text
1 - Rankinis ivedimas
2 - Generuoti tik pazymius
3 - Generuoti studentus ir pazymius
4 - Nuskaityti is failo
5 - Generuoti studentu faila
6 - Atlikti failo kurimo tyrima
7 - Atlikti v0.4 duomenu apdorojimo tyrima(vector)
8 - Atlikti v1.1 konteineriu tyrima
9 - Atlikti v1.1 skirstymo strategiju tyrima
10 - Testuoti Studentas klase
11 - Baigti
```

---

## Unit testai

v2.0 versijoje buvo pridėti unit testai.

Juos pridėjau tam, kad būtų galima patikrinti, ar pagrindiniai `Studentas` klasės metodai veikia teisingai.

Testams naudojau **Visual Studio C++ Unit Test Framework**, nes projektą darau su Visual Studio ir testus patogu paleisti per `Test Explorer`.

### Testuojami metodai

| Testas | Ką tikrina |
|---|---|
| `DefaultConstructorCreatesObject` | Patikrina, ar galima sukurti tuščią `Studentas` objektą |
| `CopyConstructorWorks` | Patikrina kopijavimo konstruktorių |
| `CopyAssignmentWorks` | Patikrina kopijavimo priskyrimo operatorių |
| `MoveConstructorWorks` | Patikrina perkėlimo konstruktorių |
| `MoveAssignmentWorks` | Patikrina perkėlimo priskyrimo operatorių |
| `InputOperatorWorks` | Patikrina įvesties operatorių `>>` |
| `OutputOperatorWorks` | Patikrina išvesties operatorių `<<` |

Svarbiausia buvo patikrinti Rule of Five metodus, nes jie parodo, ar `Studentas` objektai teisingai kopijuojami, priskiriami ir perkeliami.

### Unit testų paleidimas

Testai paleidžiami per Visual Studio:

1. Atidaryti projektą su Visual Studio.
2. Viršutiniame meniu pasirinkti `Test`.
3. Atidaryti `Test Explorer`.
4. Paspausti `Run All Tests`.

Jeigu visi testai žali, reiškia testuojami metodai veikia gerai.

---

## Doxygen dokumentacija

v2.0 versijoje projektui buvo sugeneruota dokumentacija naudojant **Doxygen**.

Dokumentacijoje aprašyta `Studentas` klasė, jos konstruktoriai, Rule of Five metodai, įvesties ir išvesties operatoriai bei kiti pagrindiniai metodai.

Dokumentacija pateikta šiais formatais:

| Dokumentacijos tipas | Vieta projekte |
|---|---|
| HTML | `docs/html/index.html` |
| LaTeX | `docs/latex/` |
| PDF | `docs/refman.pdf` |

HTML dokumentaciją galima atidaryti naršyklėje:

```text
docs/html/index.html
```

PDF dokumentacija pateikta faile:

```text
docs/refman.pdf
```

PDF failas buvo sukompiliuotas naudojant Overleaf.

---

## Relizų aprašas

### v2.0

Šioje versijoje projektas papildytas unit testais ir Doxygen dokumentacija.

Pagrindiniai pakeitimai:

- pridėti unit testai `Studentas` klasei;
- patikrinti Rule of Five metodai;
- patikrinti įvesties ir išvesties operatoriai `>>` ir `<<`;
- sugeneruota Doxygen HTML dokumentacija;
- sugeneruota Doxygen LaTeX dokumentacija;
- paruoštas dokumentacijos PDF failas;
- atnaujintas `README.md` failas;
- patikrintas projekto kompiliavimas su CMake.

---

### v1.5

Šioje versijoje programa papildyta paveldėjimu.

Buvo sukurta abstrakti bazinė klasė `Zmogus`, iš kurios paveldi `Studentas` klasė.

Programa išlaiko v1.2 versijos logiką: veikia Rule of Five, įvesties ir išvesties operatoriai bei ankstesni testai.

---

### v1.2

Šioje versijoje `Studentas` klasė papildyta Rule of Five realizacija.

Pridėta:

- destruktorius;
- kopijavimo konstruktorius;
- kopijavimo priskyrimo operatorius;
- perkėlimo konstruktorius;
- perkėlimo priskyrimo operatorius.

Taip pat realizuoti įvesties ir išvesties operatoriai `>>` ir `<<`.

---

### v1.1

Šioje versijoje `Studentas` struktūra pakeista į klasę.

Pagrindiniai pakeitimai:

- `Studentas` struktūra pakeista į klasę;
- studentų duomenys perkelti į privačius laukus;
- pridėti getteriai ir setteriai;
- realizuoti konstruktoriai ir destruktorius;
- atnaujintos funkcijos, kurios dirba su `Studentas` objektais;
- atliktas `struct` ir `class` versijų palyginimas;
- atlikta analizė su `O1`, `O2` ir `O3` optimizavimo flag'ais.

---

### v1.0

![Rezultatai](Screenshot.png)

Sukurta pradinė studento duomenų struktūra ir realizuotas pradinis vidurkio bei medianos skaičiavimas.
