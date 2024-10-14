# E2

## Popis projektu

Tento projekt implementuje základnú prácu s maticami v jazyku C. Obsahuje funkcie na vytváranie, ukladanie, načítavanie, tlačenie a operácie s maticami, vrátane násobenia matíc a invertovania matíc.

## Štruktúra MAT

Definícia štruktúry MAT, ktorá predstavuje maticu:

```c
typedef struct
{
     unsigned int rows;   // počet riadkov matice
     unsigned int cols;   // počet stĺpcov matice
     float *elem;         // pole prvkov matice
} MAT;
```

## Inverzná matica

Táto funkcia vypočíta inverznú maticu k zadanej matici.

```c
MAT *mat_invert(MAT *input_matrix);
```

### Popis

pomocou _Gaussovej eliminačnej metódy_
**input matrix:**

$$
\begin{bmatrix}
a\_{11} & a\_{12} & a\_{13} & 1 & 0 & 0 \\\
a\_{21} & a_{22} & a_{23} & 0 & 1 & 0 \\\
a\_{31} & a\_{32} & a\_{33} & 0 & 0 & 1 \\\
\end{bmatrix}
$$

**identity matrix:**

$$
\begin{bmatrix}
1 & 0 & 0 \\\
0 & 1 & 0 \\\
0 & 0 & 1 \\\
\end{bmatrix}
$$

**augmented matrix:**

$$
\begin{bmatrix}
a\_{11} & a\_{12} & a\_{13} \\\
a\_{21} & a\_{22} & a\_{23} \\\
a\_{31} & a\_{32} & a\_{33} \\\
\end{bmatrix}
$$

- **input_matrix:** Vstupná matica, ktorej inverznú maticu chceme vypočítať.
- **návratová hodnota:** Inverzná matica k vstupnej matici, alebo NULL v prípade neúspechu (napríklad ak vstupná matica nie je invertovateľná).
- funkcia predpokladá, že vstupná matica je _štvorcová_ (rovnaký počet riadkov a stĺpcov).
- v prípade, že vstupná matica nie je invertovateľná, funkcia vráti **NULL**.
- v prípade úspechu vráti funkcia inverznú maticu k vstupnej matici.




# Riešenie Lineárnych Rovníc s Maticami v C

## Prehľad

Tento program implementuje riešenie lineárnych sústav rovníc pomocou operácií s maticami v jazyku C. Najdôležitejšia časť programu rieši problém delenia matíc, kde sa použije inverzia matice na vyriešenie sústavy rovníc.

---

## Delenie Matíc – Lineárne Riešenie

Operácia **delenia matíc** v programe (funkcia `mat_division`) rieši problém vyjadrený ako:

`C = B * A^{-1}`



Kde:
- `A` je matica koeficientov, ktorá sa musí invertovať.
- `B` je matica pravých strán sústavy rovníc.
- `C` je výsledná matica, ktorá predstavuje riešenie sústavy.

### Postup pri riešení:
1. **Inverzia matice `A`:**  
   Funkcia `mat_invert` vypočíta inverznú maticu `A^{-1}` pomocou Gaussovej eliminačnej metódy. Ak matica `A` nie je štvorcová alebo nie je invertibilná (nemá riešenie), funkcia zlyhá.

   - **Gaussova eliminácia:**  
     Matica `A` sa najprv spojí s jednotkovou maticou, čím vznikne augmentovaná matica. Postupnými krokmi eliminácie sa z matice `A` stáva jednotková matica, a výsledná pravá časť tejto augmentovanej matice sa stáva jej inverziou.

2. **Násobenie matice `B` inverziou `A^{-1}`:**  
   Po získaní inverznej matice `A^{-1}` sa vykoná násobenie matíc `B * A^{-1}`, čím sa získa výsledná matica `C`. Táto operácia vypočíta riešenie sústavy lineárnych rovníc.

---

## Implementácia Funkcie `mat_division`

Funkcia `mat_division` je zodpovedná za vykonanie delenia matíc `B / A`. Ak matica `A` je invertibilná, postup je nasledovný:

1. Najprv sa pomocou funkcie `mat_invert` vypočíta inverzia matice `A`.
2. Potom sa násobí matica `B` inverznou maticou `A^{-1}`:

3. Výsledná matica `C` obsahuje riešenie sústavy lineárnych rovníc.

### Algoritmus:
- **Kontrola dimenzií:** Najprv sa skontroluje, či je počet stĺpcov matice `B` rovný počtu riadkov matice `A`, pretože len vtedy je možné vykonať násobenie.
- **Inverzia matice `A`:** Ak je matica `A` invertibilná, funkcia pokračuje.
- **Násobenie:** Matica `B` sa vynásobí inverznou maticou `A^{-1}` po prvkoch.
- **Výsledok:** Matica `C` sa naplní výsledkami násobenia a funkcia vráti úspech.

