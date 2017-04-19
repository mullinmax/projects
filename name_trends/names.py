import csv

def genorate_history_file(years, person):
	output = open("history_files/" + person['Name'] + "_" + person['Gender'] + ".txt", 'w')
	data = []
	data = total_birth_count(years, person)
	output.write(person['Name'] + person['Gender'] + "\n")
	for i in range(len(data)):
		output.write(str(data[i])+"\n")
	return (person['Name'], person['Gender'], data)

def total_birth_count(years, person):
	totals = []
	for i in range(len(years)-1):
		num = birth_count(i, years, person)
		if(num == None):
			totals.append("0")
		else:
			totals.append(num)
	return totals

def birth_count(i, years, person):
	for p in years[i]:
		if(person['Name'] == p['Name'] and person['Gender'] == p['Gender']):
			#years[i].remove(p)
			return p['Number']

def write_data(data):
	output = open("history_files/" + str(data[0]) + "_" + str(data[1]) + ".txt", 'w')
	output.write(data[0] + data[1] + "\n")
	for i in range(len(data)-2):
		output.write(str(data[i+2])+"\n")		


#read in Name Data
def main():
	years = []
	for i in range(1880,2016):
	    print("reading year " + str(i))
	    people = []
	    with open('org_data/yob' + str(i) + '.txt') as csvfile:
	        reader = csv.DictReader(csvfile,fieldnames=['Name', 'Gender', 'Number'])
	        for row in reader:
	            people.append(row)
	    years.append(people)

	

	#count total number of births for each year
	total_births = []
	for y in range(len(years)):
	    temp = 0
	    for person in years[y]:
	        temp += int(person['Number']) 
	    total_births.append(temp)

	output = open("total_births.csv", 'w')
	for i in range(len(total_births)):
		output.write(str(1880+i)+ "," + str(total_births[i])+"\n")
	
	#count occurnces of each and every name
	#history_files = []
	done_names = []
	for	y in range(len(years)):
		print(y+1880)
		for p in range(len(years[y])):
			if(not (years[y][p]['Name'], years[y][p]['Gender']) in done_names):
				done_names.append((years[y][p]['Name'], years[y][p]['Gender']))
				genorate_history_file(years[y:], years[y][p])
			#history_files.append(genorate_history_file(years[y:], years[y][0])) 
				#print(person['Name'])
	#for i in range(len(history_files)):
	#	write_data(history_files[i])

#count births of target name for each year    
'''
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
'''
#plt.show()           
            
if __name__ == '__main__':
    main()       
