# 🍽️ Sistem de Gestionare a Rezervărilor pentru Restaurante

Acest proiect reprezintă o aplicație C++ care gestionează diferite tipuri de rezervări într-un restaurant, folosind principiile programării orientate pe obiecte (POO) și moștenirea în clase.

## 📚 Descriere

Aplicația permite gestionarea rezervărilor în funcție de tipul lor:
- Rezervare Zilnică
- Rezervare Eveniment Special
- Rezervare Grup Mare
- Rezervare VIP

Fiecare rezervare conține informații despre:
- Numele clientului
- Data și ora rezervării
- Numărul de persoane

## 🧠 Scopul proiectului

Scopul acestui proiect este de a exersa utilizarea moștenirii în C++ și de a organiza datele folosind clase de bază și clase derivate.

## 📁 Structura fișierelor

- `main.cpp` – Fișierul principal în care se citește fișierul cu rezervări, se creează obiectele și se calculează prețul.
- `rezervari.txt` – Fișierul text care conține rezervările.
- `README.md` – Prezentarea proiectului.

## 📌 Cerințe implementate

- ✅ **Clasă de bază:** `Rezervare`
- ✅ **Clase derivate pentru:**
  - `RezervareZilnica`
  - `RezervareEvenimentSpecial`
  - `RezervareGrupMare`
  - `RezervareVIP`
    - ✅ Metode virtuale și suprascriere
    - ✅ Calculul tarifelor în funcție de numărul de persoane
- ✅ Citirea din fișier și stocarea în vector de pointeri
- ✅ Afișarea detaliilor rezervărilor și a prețului total
