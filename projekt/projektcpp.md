# Operacje na wektorach

## Zalożenia

    1. szablon klas punkt, wektor

    2. każda klasa ma obsłużyć twór 1, 2 lub 3 argumentowy

      u(1,2,3), v(4,2), w

    3. Operacje, które zwracają zawsze nowy twór:
      - utworzenie wektora
      - translacja o wektor
      - dodawanie wektorów
      - odejmowanie
      - oba iloczyny wektorowe
      - wektor przeciwny
      - mnożenie liczby przez wektor
      - długość wektora

## Pytania ogólne

1. Jakie typy powinny być wspierane przez szablony?

## Punkt

### Cechy

1. Podobny do klasy liczby zespolone.

      - Czy obsługuje liczby zespolone?
      - Czy potrzebna klasa "liczby zespolone", czy użyć biblioteki complex?

2. Zawiera 3 opcjonalne współrzędne.

      - Czy współrzędne powinny być przekazywane "na sztywno", tj. 3 argumenty, z wartościami domyślnymi.
      - II opcja: przekazanie wartości współrzędnych przez obiekt klasy vector lub listę inicjalizacyjną; zmienna ilość parametrów bez obciążenia pustymi wartościami.

3. Pozycja domyślna to początek układu współrzednych.
      
      - Użyć domyślnego początku?
      - Początek dla układu lini prostej, płaszczyzny, przestrzeni?

## Wektor

### Cechy

1. Zachowanie pozycji.

      - Czy wektor powinien być zawieszony w punkcie początkowym i kończyć się w punkcje końcowym?
      - Czy wektor powinien być standaryzowany do początku układu współrzędnych.

2. Sposoby tworzenia wektorów:

			- Współrzędne wektora.
			- Dwa punkty, wyliczyć różnicę, zaczepić w początku układu współrzędnych.