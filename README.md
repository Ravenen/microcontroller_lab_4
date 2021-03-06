# AVR microcontroller lab 4

## Task

1. У завданні вказується таймер за допомогою якого потрібно
   реалізувати відлік інтервалів часу для зазначеного пристрою.
   Динамічну індикацію дозволяється реалізувати за допомогою іншого
   таймера.
2. При використанні таймера 2 в асинхронному режимі передбачається,
   що він тактується від годинникового кварца 32768 Гц.
3. Тривалість звукових сигналів вибирається студентом самостійно,
   дотримуючись вказаних меж.
4. Парні варіанти вибирають підключення семисегментників зі
   спільним анодом, а непарні варіанти – зі спільним катодом.

| Таймер відліку часу | Частота тактування, МГц | Кнопки  | Сигнал | Порт керування 7-сегм | Виводи керування напругами | Алгоритм |
| ------------------- | ----------------------- | ------- | ------ | --------------------- | -------------------------- | -------- |
| T1                  | 4                       | PA(4-7) | PD4    | PORTB                 | PC(1-6)                    | 1        |

### Опис алгоритму

**Годинник.**
Відображає години, хвилини, секунди. Запускається одразу ж при подачі живлення на МК. При співпадінні значень будильника та годинника запускається звуковий сигнал (короткими гудками) тривалістю 0,5-2 хв.

Кнопка 1 – виставляє значення годин годинника або будильника.  
Кнопка 2 – виставляє значення хвилин годинника або будильника.  
Кнопка 3 – відображає значення будильника та дає можливість кнопками 1 та 2 змінювати його значення.  
Кнопка 4 – активізує/відключає будильник (при натисненій кнопці 3), якщо будильник активований, то у секції секунд відображається літера А.

## Getting Started

### Prerequisites

- Install [VS Code](https://code.visualstudio.com/Download)
- Install [PlatformIO](https://platformio.org/install/ide?install=vscode)
- Install [Proteus](https://www.labcenter.com/)

### Installing

- Clone repository into your system

```
git clone https://github.com/Ravenen/microcontroller_lab_4.git
```

### Executing program

- Build a project in `code` folder via PlatformIO builder
- Open Proteus project and run the simulation

## Authors

[Vitaliy Pavliyk (@ravenen)](https://github.com/Ravenen)
