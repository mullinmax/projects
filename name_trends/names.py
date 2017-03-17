import csv
import matplotlib.pyplot as plt

#read in Name Data
years = []
for i in range(1880,2016):
    print("reading year " + str(i))
    people = []
    with open('yob' + str(i) + '.txt') as csvfile:
        reader = csv.DictReader(csvfile,fieldnames=['Name', 'Gender', 'Number'])
        for row in reader:
            people.append(row)
    years.append(people)


    
#count total number of births for each year
total_births = []
for y in range(len(years)):
    temp = 0
    for person in years[y]:
        if(person['Gender'] == 'F'):
            temp += int(person['Number']) 
    total_births.append(temp)
        
    
#count births of target name for each year    
plot_data = []
found = False;
for p in range(0,100):
    print (years[0][p]['Name'], years[0][p]['Number'])
    temp = []
    for y in range(len(years)):
        for name in years[y]:
            if(name['Name'] == years[0][p]['Name'] and name['Gender'] == years[0][p]['Gender']):
            #if((name['Name'] == "Brittney" or name['Name'] == "") and name['Gender'] == "F"):
                temp.append(int(name['Number'])/total_births[y])
                break
        plot_data.append(temp)
for i in range(len(plot_data)):
    plt.plot(plot_data[i])
plt.savefig('destination_path.png', format='png', dpi=1000)
print ("done")
#plt.show()           
            
            