# Základný obraz z Docker Hub
# Fungujúca inštalácia Alpine Linux s nainštalovaným interpreterom Python
# Výhodou je malá veľkosť
FROM python:3.8-alpine

# Nastavenie pracovného adresára kontajnera
WORKDIR /app

# Virtuálne prostredie nie je potrebné

# Inštalácia  závislostí aplikácie priamo do systému
RUN pip install flask

# Kopírovanie súborov aplikácie do obrazu
COPY ./app.py /app

# Nastavenie premennej prostredia
ENV FLASK_APP app.py

# Program na spustenie
ENTRYPOINT [ "flask" ]
# Argumenty 
CMD ["run", "--host", "0.0.0.0"]
# V kontajneri sa spustí flask vo vývojovom režime  takto:
# flask run --host 0.0.0.0
