---
title: Úvod do virtualizácie
published: true
visible: true
display_custom_links: true
custom_links:
    - text: PDF
      url: '/zkt/prednasky/virtualizacia/?print-pdf=true'
    - text: Video z 16.2.2021
      url: 'https://files.kemt.fei.tuke.sk/predmety/zkt/videa/zkt21pr1.mp4'
---

# Úvod do virtualizácie

- Základné pojmy
- Motivácia

----
## Virtualizácia

je vrstva oddeľujúca  operačný systém a fyzický hardvér.

```
HOST HW and OS

Virtualization

GUEST OS and APP
```

---
## Virtuálny počítač

Vvytvára oddelený "svet" pre aplikáciu:

- Virtuálna pamäť
- Virtuálny procesor
- Virtuálna sieťová a grafická karta, atď.

Je jedno kde fyzicky beží. 

----
## Kde beží virtualizácia?

**Hardvérová virtualizácia** - proces beží na virtuálnom procesore. Je možné spúšťať ľubovoľné programy pre ľubovoľnú architektúru aj OS. 
Je pomalšia.

**Paravirtualizácia** - proces beží na fyzickom procesore. Nie je možné spúšťať programy pre inú architektúru. Je rýchlejšia. Potrebuje podporu BIOSu.


----
## Ako spustiť virtuálny stroj?

hypervisor alebo monitor


---
## Hypervisor

Virtualizačná vrstva je súčasťou Host OS

```
Host HW
Hypervisor
Guest OS
Guest APP
```

napr. VM Ware ESX, Xen, Qemu / KVM

---
## Monitor virtuálnych strojov

Monitor je jedna z aplikácií Host OS

```
Host HW
Host OS
Virtual Machine Monitor
Guest OS
Guest APP
```

napr. Virtual Box, 

---
# Motivácia 

----
## Prečo virtualizácia?

- uľahčenie manažmentu infraštrkutúry
- uľahčenie vývoja
- uľahčenie procesu nasadenia aplikácie
----
### Virtualizácia maže rozdiely medzi systémami.

- Aplikácia sa vie za behu "sťahovať" medzi systémami.
- Aplikácia vie bežať na viacrerých systémoch naraz.
- Jeden systém vie obslúžiť viac aplikácií naraz.

----

Je možné si prenajať len časť prostriedkov stroja.

Virtuálna infraštruktúra môže byť úplne odlišná od fyzickej infraštruktúry.

----
Virtualizačná vrstva je programovateľná

Vieme:

- vytvoriť stroj (prideliť prostriedky)
- zrušiť stroj
- spustiť alebo zastaviť stroj
- klonovať alebo presunúť stroj

---
## Infrastructure as code

Ak naša fyzická infraštruktúra využíva virtualizáciu

- sieť
- diskový priestor
- virtuálne stroje
- fyzické stroje

Virtuálnu Infraštruktúru vieme vyjadriť pomocou skriptov a konfiguračných súborov.

napr. 

- Terraform
- Vagrant

----
Orchestrátor

Nástroje na ovládanie virtualizovanej (alebo fyzickej) infraštruktúry vo veľkom.

```
Fyzická infraštruktúra <=> virtualizačná vrstva <=> orchestrátor
```

- Ansible
- Chef
- Puppet

----
## Zdroje

- [Sean Campbell and Michael Jeronimo](https://software.intel.com/sites/default/files/m/d/4/1/d/8/An_Introduction_to_Virtualization.pdf ), Intel 2006
- [IoC at Wikipedia](]https://en.wikipedia.org/wiki/Infrastructure_as_code)

### Aj prehliadač je virtuálny stroj

- [DOS Fun](https://js-dos.com/games/).
- [Windows 95](https://win95.ajf.me/) z roku 1995.


----
## Ako si spustím virtuálny stroj?

na svojom PC

1. Nainštalujem si monitor virtuálnych strojov
2. Získam obraz disku virtuálneho stroja
3. Nakonfigurujem virtuálny stroj (pridelím prostriedky)
4. Spustím virtuálny stroj
