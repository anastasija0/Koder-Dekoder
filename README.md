# Koder-Dekoder

Cilj projekta je kreiranje kodera koji bi niz cifara kodirao u jedinstvenu šifrovanu poruku - i dekodera koji bi dekodirao ovu poruku. Moguće primene su u kodiranju brojeva telefona, lozinki, IP adresa ili drugih bitnih nizova cifara radi bezbednijeg slanja preko interneta. Projekat je realizovan u programskom jeziku C++.

# Ideja

Ideja za koder zasniva se na rimskim ciframa. Svake 3 (najviše 3, a najmanje 1) uzastopne cifre posmatrane su kao trocifren broj, i po modifikovanom principu rimskih cifara kodirane u niz slova. Koder svaku od cifara predstavlja kao string od 4 slova, pa je tako 0: *aaaa*, 1: *baaa*... gde se pažnja pridaje ascii vrednostima slova. Koder slično šifruje i cifre desetica, odnosno stotina. Dekoder radi na obrnutom principu, prepoznajući grupe od 4 * 3 = *12* slova i smanjujući ascii vrednosti i prateći algoritam kodera vraća početni niz cifara.
