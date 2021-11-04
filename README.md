# Objektinio programavimo Pirma-uzduotis

# 0.1V

0.1V programa yra "1 Uzduotis" folderyje.

0.1 versijoje yra įdiegtos visos šios numatytos funkcijos:

*Automatinė studentų kiekio užklausa : paklausiama, kiek studentų duomenų vartotojas ketina vesti (1-20 studentų).

*Nuskaitomas studento vardas ir pavardė.

*Automatinė studento namų darbų užklausa: klausiama, ar vartotojas žino namų darbų skaičių.

**Jei nežino, jis gali ranka vesti pažymius tol, kol konsolėje surinks -1, jei leis pažymius vesti kompiuteriui, jis tokiu atveju sugeneruos tik 10 pažymių.

**Jei žino, vartotojui leidžia vesti/sugeneruoti tik numatytą namų darbų skaičių.

*Automatiškai sugeneruojamas ir arba įvedamas ranka pasirinktas kiekis namų darbų pažymių.

*Išrašytas arba sugeneruotas pažymių masyvas yra atspausdinamas didėjimo tvarka, kad būtų galima lengviau pastebėti akimi medianą, be to, matyti visus įvestus pažymius didėjimo tvarka.

*Namų darbai yra laikomi vektoriuje, tačiau viename iš subreleasų atsiranda galimybė juos laikyti ir dinaminiame masyve.

*Automatiškai  arba ranka sugeneruojamas(įvedamas) egzamino pažymys, bei išvedamas ekrane.

*Vartotojas yra klausiamas ar nori galutinį balą matyti suskaičiuotą pagal vidurkį ar pagal medianą.

*Visų studentų vardai, pavardės ir galutiniai balai (pasirinktinai nuo vartotojo ar su mediana, ar su vidurkiu) yra išvedami tvarkingai lentelėje.

Atlikti pataisymai tarp papildymų:

**V0.1 galutinėje versijoje (release) yra sutvarkytas medianos skaičiavimas, kuris buvo klaidingas "V0.1 papildymas(mediana)", "V0.1.2", "V0.1.2Masyvas" subreleasuose.

**Tarp subreleasų iki releaso yra atlikti nežymūs kodo potvarkiai, ištrintos nereikalingos/blogos eilutės, ištaisytos mažos klaidelės.

**Galutiniame kode(V0.1FINALRELEASE) yra visų prieš tai buvusių subreleasų galimybės.

# 0.2V

*Programoje atsiranda galimybė skaityti studentų duomenis iš txt failo (kursiokai.txt). Vartotojo klausiama, ar šis duomenis ketina vesti pats, ar nori nuskaityti iš txt failo.

***Pridėtas SRAND().
*Programa klausia, ar studentų failą(txt) norima tiesiog nuskaityti (gauti lentelę su jų vardais, pavardėm, namų darbų pažymiais bei egzamino pažymiu) ar išvesti studentų vardus, pavardes, galutinius pažymius pagal medianą ir vidurkį. Abiem atvejais programa įvykdo tą, ko vartotojas prašo.

# 0.3V

0.3 versijoje sėkmingai įdiegtas exception handlingas - jei blogai įvesta raidė ar skaičius, kompiuteris praneša, jog įvestis buvo bloga, tas pats veikia su failo skaitymu - jei failas nenuskaitomas, nes jo neranda, tai kompiuteris praneša, jog tokio failo nėra sistemoje. Nega to, visos funkcijos yra išskaidytos į .cpp ir header .h failus, o programos veikimas nuo to nepasikeitė.

# 0.5V

Naujojoje 0.5 versijoje galima nuskaityti studentus iš listo ir taip pat apskaičiuoti kiek laiko užtrunka duomenų nuskaitymas iš failų, kiek laiko užtrunka rūšiavimas į dvi kategorijas. Šioje versijoje taip pat yra buvusių versijų galimybės - vedimas ranka, pažymių automatizavimas, nuskaitymas iš vektoriaus ir t.t, taigi, ši versija apibendrina visas buvusias galimybes ir turi naują - nuskaitymą iš listo.
Dėl labai ilgų rūšiavimo ir išvedimo į du failus laikų, programa buvo ištestuota su 1000, 10 000, 100 000 studentų sąrašais ( rezultatų nuotraukos įkeltos prie darbo), norint testuoti su didesniu studentų sąrašu, prireiktų kelių dešimčių valandų, 10 000 000 atveju greičiausiai ir dienų. Visuose testuose nustatytas namų darbų skaičius - 5, skaičiuojama pagal vidurkį, o ne pagal medianą ( galima keisti tiek namų darbų skaičių, tiek galutinio balo skaičiavimo būdą, tačiau tų rezultatų nedėjau, nes nemanau, kad yra prasmė).
Kompiuterio specifikacijos :
Intel Core i7-10750H CPU @2.6Ghz
16GB RAM
512GB SSD
GTX 1650
