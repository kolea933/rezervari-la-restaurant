# 🍽️ Sistem de Gestionare a Rezervărilor pentru Restaurante

Acest proiect reprezintă o aplicație C++ care gestionează diferite tipuri de rezervări într-un restaurant, folosind principiile programării orientate pe obiecte (OOP) și moștenirea în clase.

## 📚 Descriere

Aplicația permite gestionarea rezervărilor în funcție de tipul lor:
- Rezervare Zilnică
- Rezervare Eveniment Special
- Rezervare Grup Mare
- Rezervare VIP *(bonus obligatoriu)*

Fiecare rezervare conține informații despre:
- Numele clientului
- Data și ora rezervării
- Numărul de persoane

## 🧠 Scopul proiectului

Scopul acestui proiect este de a exersa utilizarea moștenirii în C++ și de a organiza datele folosind clase de bază și clase derivate.

## 📁 Structura fișierelor

- `main.cpp` – Fișierul principal în care se citește fișierul cu rezervări, se creează obiectele și se calculează prețul.
- `Rezervare.hpp` – Clasa de bază `Rezervare` și clasele derivate.
- `fisier_date.txt` – Fișierul text care conține rezervările.
- `README.md` – Prezentarea proiectului.

## 📌 Cerințe implementate

✔️ Clasă de bază `Rezervare`  
✔️ Clase derivate pentru:
- RezervareZilnica
- RezervareEvenimentSpecial
- RezervareGrupMare
- RezervareVIP *(opțional obligatoriu)*  
✔️ Metode virtuale și suprascriere  
✔️ Calculul tarifelor în funcție de numărul de persoane  
✔️ Citirea din fișier și stocarea în vector de pointeri  
✔️ Afișarea detaliilor rezervărilor și a prețului total

## 📥 Exemplu de format pentru `fisier_date.txt`:

RezervareZilnica TudorPopescu 2025-02-27 19:00 4 
RezervareEvenimentSpecial MariaIonescu 2025-03-01 18:00 12 
RezervareGrupMare AndreiVasile 2025-03-05 20:00 25 
RezervareVIP ElenaDumitru 2025-03-10 21:00 5

