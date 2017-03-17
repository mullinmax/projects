import csv
import matplotlib.pyplot as plt

years = []
for i in range(1880,2016):
    print("reading year " + str(i))
    people = []
    with open('yob' + str(i) + '.txt') as csvfile:
        reader = csv.DictReader(csvfile,fieldnames=['Name', 'Gender', 'Number'])
        for row in reader:
            people.append(row)
    years.append(people)
print (int(years[1880-1880][0]['Number']))            
plot_data = []
start = -1
stop = -1
for y in range(len(years)):
    temp = 0
    found = False;
    for name in years[y]:
        if((name['Name'] == "Max" or name['Name'] == "Maxwell") and name['Gender'] == "M"):
            found = True
            if(start == -1):
                start = y
            stop = y
            temp = temp + int(name['Number'])
    if(found):
        plot_data.append(temp)
print (start+1880, stop+1880)
plt.plot(plot_data)
plt.show()           
            
            