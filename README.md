# Laboratorio per il corso di Algoritmi e Strutture Dati: indicazioni generali e suggerimenti, consegne per gli esercizi
## Linguaggio in cui sviluppare il laboratorio

Gli esercizi vanno implementati utilizzando il linguaggio C o Java come precisato di seguito:

- Esercizio 1: C
- Esercizio 2: C o Java a discrezione dello studente
- Esercizio 3: Java
- Esercizio 4: Java

Come detto, gli esercizi chiedono di realizzare strutture generiche. Seguono alcuni suggerimenti sul modo di realizzarle nei due linguaggi accettati.

**Nota importante** : Con "strutture dati generiche" si fa riferimento al fatto che le strutture dati realizzate devono poter essere utilizzate con tipi di dato non noti a tempo di compilazione.
Nota: chi è in grado di realizzare tipi di dato astratto tramite tipi opachi è incoraggiato a procedere in questa direzione.

**Suggerimenti (Java)**: Sebbene in Java la soluzione più in linea con il moderno utilizzo del linguaggio richiederebbe la creazione di classi parametriche, tutte le scelte implementative (compresa la decisione di usare o meno classi parametriche) sono lasciate agli studenti. Inoltre, è possibile (e consigliato) usare gli ArrayList invece degli array nativi al fine di semplificare l'implementazione delle strutture generiche.

## Uso di librerie esterne e/o native del linguaggio scelto
Nello sviluppo in Java l'uso di ArrayList, ove non escluso esplicitamente dalla consegna dell'esercizio, è da ritenersi possibile.

È, invece, sempre proibito (sia nello sviluppo in Java che in quello in C) l'uso di strutture dati native del linguaggio scelto o offerte da librerie esterne, quando la loro realizzazione è richiesta da uno degli esercizi proposti.

## Qualità dell'implementazione

È parte del mandato degli esercizi la realizzazione di codice di buona qualità.

Per "buona qualità" intendiamo codice ben modularizzato, ben commentato e ben testato.

## Unit Testing

Come indicato esplicitamente nei testi degli esercizi, il progetto di laboratorio comprende anche la definizione di opportune suite di unit tests.

Si rammenta, però, che il focus del laboratorio è l'implementazione di strutture dati e algoritmi. Relativamente agli unit-test sarà quindi sufficiente che gli studenti dimostrino di averne colto il senso e di saper realizzare una suite di test sufficiente a coprire i casi più comuni (compresi, in particolare, i casi limite).

## Esercizio 1 

### Linguaggio richiesto: C

### Testo

Si consideri il tipo di dato astratto Lista, definito nei termini delle seguenti operazioni:

- Verifica se la lista è vuota in O(1)
- Inserimento in coda alla lista in O(1) 
- Inserimento di un elemento nella posizione i-esima della lista in O(n)
- Cancellazione dell'elemento in coda alla lista in O(1)
- Cancellazione dell'elemento in posizione i-esima nella lista in O(n)
- Recupero dell'elemento in posizione i-esima nella lista (senza cancellare l'elemento dalla lista) in O(n)
- Recupero del numero di elementi della lista in O(1) 
- Creazione di un iteratore per la lista in O(1)

La lista può contenere oggetti di tipo qualunque e non noto a priori.

Un iteratore è un tipo di dato astratto che permette di iterare su un container di qualche tipo. Un iteratore deve mettere a disposizione le seguenti operazioni:

- Verifica se l'iteratore è ancora valido in O(1) (un iteratore è inizializzato in modo da fare riferimento alla testa della lista e diventa invalido quando viene spostato oltre la fine della lista).
- Recupera l'elemento corrente in O(1)
- Sposta l'iteratore all'elemento successivo in O(1)


Si realizzino in C due implementazioni alternative per il tipo di dato astratto Lista (e, conseguentemente per l'iteratore su di essa).

In particolare:

- entrambe le implementazioni devono offrire:
    - una funzione per creare una lista vuota;
    - una per distruggerla (con conseguente deallocazione della memoria associata);
    - una funzione per distruggere un iteratore (con conseguente deallocazione della memoria associata);
    - tutte e sole le operazioni specificate sopra; tali operazioni devono essere realizzate tramite funzioni aventi la stessa signature in entrambe le librerie;
- una implementazione deve realizzare le liste con array dinamici (cioè ridimensionabili); l'altra implementazione deve realizzare le liste tramite record collegati.



### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento Unit Testing.

### Uso delle librerie implementate

Implementare un algoritmo _merge_ che accetta in input un criterio di ordinamento e due liste ordinate secondo tale criterio di ordinamento e restituisce in output una nuova lista, corrispondente alla fusione delle due liste di input e ordinata secondo lo stesso criterio.

L'algoritmo implementato deve poter essere eseguito \*senza modifiche\* su ciascuna delle due implementazioni per il tipo di dato astratto Lista prodotte secondo le specifiche riportate sopra.

### Unit Testing

Implementare gli unit-test per la funzione che implementa _merge_ secondo le indicazioni suggerite nel documento Unit Testing.

## Esercizio 2

### Linguaggio richiesto: C o Java

### Testo

Si consideri il problema di determinare la distanza di edit tra due stringhe (Edit distance): date due stringhe s1 e s2, non necessariamente della stessa lunghezza, determinare il minimo numero di operazioni necessarie per trasformare la stringa s2 in s1. Si assuma che le operazioni disponibili siano: cancellazione, inserimento, e rimpiazzamento di un carattere. Esempi:

- "casa" e "cassa" hanno edit distance pari a 1 (1 cancellazione);
- "casa" e "cara" hanno edit distance pari a 1 (1 rimpiazzamento);
- “vinaio” e “vino” hanno edit distance=2 (2 inserimenti);
- "tassa" e "passato" hanno edit distance pari a 3 (2 cancellazioni + 1 rimpiazzamento);
- "pioppo" e "pioppo" hanno edit distance pari a 0.

1. Si implementi una versione ricorsiva della funzione edit\_distance basata sulle seguenti osservazioni (indichiamo con $|s|$ la lunghezza di $s$ e con $\mathrm{rest}(s)$ la sottostringa di $s$ ottenuta ignorando il primo carattere di $s$):

- se $|s1|$ = 0, allora $\mathrm{edit\_distance}(s1,s2) = |s2|$;
- se $|s2|$ = 0, allora $\mathrm{edit\_distance}(s1,s2) = |s1|$;
- altrimenti, siano:
  - $d_{\mathrm{no-op}} = 
        \begin{cases}
        \mathrm{edit\_distance}(\mathrm{rest}(s1),\mathrm{rest}(s2)) & \mathrm{se\ } s1[0]=s2[0] \\
        \infty & \mathrm{altrimenti}
        \end{cases}$

  - $d_{\mathrm{canc}} = 1+ \mathrm{edit\_distance}(s1,\mathrm{rest}(s2))$
  - $d_{\mathrm{ins}} = 1+ \mathrm{edit\_distance}(\mathrm{rest}(s1),s2)$
  - $d_{\mathrm{replace}} = 1 + \mathrm{edit\_distance}(\mathrm{rest}(s1), \mathrm{rest}(s2))$

Si ha: $\mathrm{edit\_distance}(s1,s2)=\min\{d_{\mathrm{no-op}},d_{\mathrm{canc}},d_{\mathrm{ins}},d_{\mathrm{replace}}\}$

1. Si implementi una seconda versione edit\_distance\_dyn della funzione, adottando una strategia di programmazione dinamica. Tale versione deve essere anch'essa ricorsiva (in particolare, essa può essere facilmente ottenuta a partire dall'implementazione richiesta al punto precedente).

Nota: Le definizioni sopra riportate non corrispondono al modo usuale di definire la distanza di edit. Sono del tutto sufficienti però per risolvere l'esercizio e sono quelle su cui dovrà essere basato il codice prodotto.

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento Unit Testing.

### Uso delle funzioni implementate

Il file dictionary.txt che potete trovare seguendo il path

/usr/NFS/Linux/labalgoritmi/datasets/

(in laboratorio von Neumann, selezionare il disco Y) contiene l'elenco (di una parte significativa) delle parole italiane. Le parole sono scritte di seguito, ciascuna su una riga.

Il file correctme.txt contiene una citazione di John Lennon. Il file contiene alcuni errori di battitura.

Si implementi un'applicazione che usa la funzione edit\_distance\_dyn per determinare, per ogni parola w in correctme.txt, la lista di parole in dictionary.txt con edit distance minima da w. Si sperimenti il funzionamento dell'applicazione e si riporti in una breve relazione (circa una pagina) i risultati degli esperimenti.

**I FILE dictionary.txt E correctme.txt NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

## Esercizio 3

### Linguaggio richiesto: Java

### Testo

Si implementi la struttura dati Union-Find Set. La struttura dati deve permettere di inserire oggetti di tipo generico e non deve prevedere alcuna cardinalità massima per l'insieme iniziale di elementi.

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento Unit Testing.

## Esercizio 4

### Linguaggio richiesto: Java

### Testo

Si implementi una libreria che realizza la struttura dati Grafo in modo che **sia ottimale per dati sparsi** 
(IMPORTANTE: le scelte implementative che farete dovranno essere giustificate in relazione alle nozioni presentate 
durante le lezioni in aula). La struttura deve consentire di rappresentare sia grafi diretti che grafi non diretti 
(suggerimento:  un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata 
per garantire che, per ogni arco (a,b), etichettato w, presente nel grafo, sia presente nel grafo anche l'arco (b,a), 
etichettato w. Ovviamente, il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.).

L'implementazione deve essere generica sia per quanto riguarda il tipo dei nodi, sia per quanto riguarda le etichette 
degli archi.

La struttura dati implementata dovrà offrire (almeno) le seguenti operazioni (accanto ad ogni operazione è specificata la 
complessità richiesta; n può indicare il numero di nodi o il numero di archi, a seconda del contesto):

- Creazione di un grafo vuoto – O(1)
- Aggiunta di un nodo – O(1)
- Aggiunta di un arco – O(1)
- Verifica se il grafo è diretto – O(1)
- Verifica se il grafo contiene un dato nodo – O(1)
- Verifica se il grafo contiene un dato arco – O(1) quando il grafo è veramente sparso
- Cancellazione di un nodo – O(n)
- Cancellazione di un arco – O(1) quando il grafo è veramente sparso
- Determinazione del numero di nodi – O(n)
- Determinazione del numero di archi – O(n)
- Recupero dei nodi del grafo – O(n)
- Recupero degli archi del grafo – O(n)
- Recupero nodi adiacenti di un dato nodo – O(n)
- Recupero etichetta associata a una coppia di nodi – O(1) quando il grafo è veramente sparso.

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento Unit Testing.

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'algoritmo di Kruskal per la determinazione della minima foresta  ricoprente di un grafo.

L'implementazione dell'algoritmo di Kruskal dovrà utilizzare la struttura dati Union-Find Set implementata 
nell' esercizio precedente.

N.B. Nel caso in cui il grafo sia costituito da una sola componente connessa, 
l'algoritmo restituirà un albero; nel caso in cui, invece, vi siano più componenti connesse, 
l'algoritmo restituirà una foresta costituita dai minimi alberi ricoprenti di ciascuna componente connessa.

### Uso delle librerie che implementano la struttura dati Grafo e l'algoritmo di Kruskal

La struttura dati Grafo e l'algoritmo di Kruskal dovranno essere utilizzati con i dati contenuti nel file italian\_dist\_graph.csv.

Il file italian\_dist\_graph.csv che potete recuperare seguendo il path

/usr/NFS/Linux/labalgoritmi/datasets/

(in laboratorio von Neumann, selezionare il disco Y) contiene le distanze in metri tra varie località 
italiane e una frazione delle località a loro più vicine. 
Il formato è un CSV standard: i campi sono separati da virgole; i record sono separati dal carattere di fine 
riga (\\n).

Ogni record contiene i seguenti dati:

- località 1: (tipo stringa) nome della località "sorgente". La stringa può   contenere spazi, non può contenere virgole;
- località 2: (tipo stringa) nome della località "destinazione". La stringa  può contenere spazi, non può contenere virgole;
- distanza: (tipo float) distanza in metri tra le due località.

**Note** :

- potete interpretare le informazioni presenti nelle righe del file come   archi non diretti (i.e., probabilmente vorrete inserire nel vostro grafo sia l'arco di andata che quello di ritorno a fronte di ogni riga letta).
- il file è stato creato a partire da un dataset poco accurato. I dati riportati contengono inesattezze e imprecisioni.

**IL FILE italian\_dist\_graph.csv NON DEVE ESSERE OGGETTO DI COMMIT SU GIT!**

**Controlli**

Un'implementazione corretta dell'algoritmo di Kruskal, eseguita sui dati 
contenuti nel file italian\_dist\_graph.csv, dovrebbe determinare una minima foresta ricoprente con 
18.640 nodi, 18.637 archi (non orientati) e di peso complessivo di circa 89.939,913 Km.
