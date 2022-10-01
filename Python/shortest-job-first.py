import numpy as np
import pandas as pd
from tabulate import tabulate
import matplotlib.pyplot as plt
#%matplotlib inline
import numpy as np
import matplotlib.pyplot as plt

step=int(input("Enter the number of steps:"))
x = np.zeros(step+1)
y = np.zeros(step+1)
z= np.zeros(step+1)


df = pd.DataFrame( {'Step':[],'Random\nNumber':[],'Direction':[],'X':[],'Y':[],'Z':[]})

for i in range(1,step+1):
    footstep=np.random.randint(0,20)
    if footstep<=4:
        direction='F'
        y[i]=y[i-1]+1
        x[i]=x[i-1]
        z[i]=z[i-1]
    elif footstep>=5 and footstep<=6:
        direction = 'B'
        y[i] = y[i - 1] - 1
        x[i] = x[i - 1]
        z[i] = z[i - 1]
    elif footstep>=7 and footstep<=9:
        direction='U'
        z[i] = z[i - 1]+1
        y[i] = y[i - 1]
        x[i] = x[i - 1]
    elif  footstep>=10 and footstep<=11:
        direction='D'
        z[i] = z[i - 1] - 1
        y[i] = y[i - 1]
        x[i] = x[i - 1]
    elif footstep >=12  and footstep <= 15:
        direction = 'R'
        x[i] = x[i - 1] + 1
        y[i] = y[i - 1]
        z[i] = z[i - 1]
    else:
        direction='L'
        x[i]=x[i-1]-1
        y[i]=y[i-1]
        z[i] = z[i - 1]

    value={'Step':i,'Random\nNumber': footstep,'Direction': direction,'X':x[i],'Y':y[i],'Z':z[i]}
    df=df.append(value,ignore_index=True)

df.set_index("Step", inplace=True)
print(tabulate(df, headers = 'keys', tablefmt = 'psql'))
print(f"After {step} steps the drunkard moves to the position ({x[step]},{y[step]},{z[step]})")


#fig = plt.figure('Random walk 3D')
#plt.title("Random Walk ($n = " + str(step) + "$ steps)")
#plt.xlabel("X-AXIS")
#plt.ylabel("Y-AXIS")
fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot3D(x, y, z, 'red')

plt.show()