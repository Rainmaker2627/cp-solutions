a,b,c=input(),input(),input()
pin=a.replace("<","")[-11:]
name,surname=c.replace("<"," ").split()
day,month,year=b[4:6],b[2:4],b[0:2]
if int(year)<=24: year="20"+year
else: year="19"+year
print("Ime:",name.capitalize())
print("Prezime:",surname.capitalize())
print(f"Datum rodjenja: {day}-{month}-{year}")
print("OIB:",pin)