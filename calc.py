import pandas as pd

obj = pd.read_csv('Turbo MIS.csv')
successcount = 0
faliurecount = 0

for i in range(0, len(obj)):
    if(obj["RCU Decision"][i] == obj["status"][i]):
        obj["value"][i] = 1
        
        successcount += 1
    else:
        obj["value"][i] = 0
        faliurecount += 1
obj.iloc[:,:]
obj.to_csv('value.csv')
succPercent = (successcount/len(obj))*100
faliureper = (faliurecount/len(obj))*100
print("Correctly Predicted status count = ")
print(successcount)
print("Wrongly Predicted status count = ")
print(faliurecount)
print("Success Percent: ")
print(succPercent)
print("Faliure Percent: ")
print(faliureper)
