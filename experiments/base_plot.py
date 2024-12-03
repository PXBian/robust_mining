import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


# Change tau
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_tau.csv")
n = []
tau = []
k = []
bl_runtime = []
st_runtime = []
esa_runtime = []

bl_mem = []
st_mem = []
esa_mem = []


for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    bl_mem.append(row['bl_mem'] / 1000)
    st_mem.append(row['st_mem'] / 1000)
    esa_mem.append(row['esa_mem'] / 1000)

    bl_runtime.append(row['bl_time'])
    st_runtime.append(row['st_time'])
    esa_runtime.append(row['esa_time'])



## Runtime
bar_width = 0.9
n_positions = np.arange(len(tau))
plt.bar(n_positions - bar_width/3, bl_runtime, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_runtime, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_runtime, width=bar_width/3, color='orange', label='RPM-ESA')

plt.yscale('log')
plt.xlabel(r"$\tau$", fontsize=30)
plt.ylabel("Runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
ticks = [10**-2, 10**0, 10**2, 10**4]
plt.yticks(ticks, [r'$10^{-2}$', r'$10^0$', r'$10^2$', r'$10^4$'], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_tau.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# # # Memory
bar_width = 0.9
n_positions = np.arange(len(tau))
plt.bar(n_positions - bar_width/3, bl_mem, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_mem, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_mem, width=bar_width/3, color='orange', label='RPM-ESA')
plt.xlabel(r"$\tau$", fontsize=30)
plt.ylabel("Memory (MB)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_tau.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# # Memory
# bar_width = 0.4
# n_positions = np.arange(len(tau))
# plt.bar(n_positions - bar_width/2, bl_mem, width=bar_width, color='b', label='Baseline')
# plt.bar(n_positions + bar_width/2, main_mem, width=bar_width, color='r', label='RPM-ST')
# # plt.ylim(1, pow(10,5))
# # plt.ylim(0, max(bl_mem) + 1000)

# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# # plt.yscale('log')
# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("memory (MB)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
# plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_tau.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# ## Change k
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_k.csv")
n = []
tau = []
k = []
bl_runtime = []
st_runtime = []
esa_runtime = []

bl_mem = []
st_mem = []
esa_mem = []


for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    bl_mem.append(row['bl_mem'] / 1000)
    st_mem.append(row['st_mem'] / 1000)
    esa_mem.append(row['esa_mem'] / 1000)

    bl_runtime.append(row['bl_time'])
    st_runtime.append(row['st_time'])
    esa_runtime.append(row['esa_time'])



# ## Runtime
bar_width = 0.9
n_positions = np.arange(len(k))
plt.bar(n_positions - bar_width/3, bl_runtime, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_runtime, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_runtime, width=bar_width/3, color='orange', label='RPM-ESA')

plt.yscale('log')
plt.xlabel(r"$k$", fontsize=30)
plt.ylabel("Runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
ticks = [10**-2, 10**0, 10**2, 10**4]
plt.yticks(ticks, [r'$10^{-2}$', r'$10^0$', r'$10^2$', r'$10^4$'], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_k.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# # # Memory
bar_width = 0.9
n_positions = np.arange(len(k))
plt.bar(n_positions - bar_width/3, bl_mem, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_mem, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_mem, width=bar_width/3, color='orange', label='RPM-ESA')

plt.xlabel(r"$k$", fontsize=30)
plt.ylabel("Memory (MB)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_k.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# ## Change n
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_n.csv")
n = []
tau = []
k = []
bl_runtime = []
st_runtime = []
esa_runtime = []

bl_mem = []
st_mem = []
esa_mem = []

for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    bl_mem.append(row['bl_mem'] / 1000)
    st_mem.append(row['st_mem'] / 1000)
    esa_mem.append(row['esa_mem'] / 1000)

    bl_runtime.append(row['bl_time'])
    st_runtime.append(row['st_time'])
    esa_runtime.append(row['esa_time'])


    if(row['dataset'] == 'ecoli1000'):
        n.append(1000)
    elif(row['dataset'] == 'ecoli2000'):
        n.append(2000)
    elif(row['dataset'] == 'ecoli5000'):
        n.append(5000)
    elif(row['dataset'] == 'ecoli10000'):
        n.append(10000)
    elif(row['dataset'] == 'ecoli20000'):
        n.append(20000)
    elif(row['dataset'] == 'ecoli50000'):
        n.append(50000)
    elif(row['dataset'] == 'ecoli100000'):
        n.append(100000)


# print(n)
# print(bl_mem)
# print(bl_runtime)
# print(main_mem)
# print(main_runtime)

## Runtime
bar_width = 0.9
n_positions = np.arange(len(n))
# print(n_positions)
plt.bar(n_positions - bar_width/3, bl_runtime, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_runtime, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_runtime, width=bar_width/3, color='orange', label='RPM-ESA')
# plt.ylim(0.001, 10000)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale('log')
plt.yscale('log')
plt.xlabel(r"$n$", fontsize=30)
plt.ylabel("Runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.03, 1.04), fontsize=25)
plt.xticks(n_positions, [5000,10000,20000,50000,100000], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
ticks = [10**-2, 10**0, 10**2, 10**4]
plt.yticks(ticks, [r'$10^{-2}$', r'$10^0$', r'$10^2$', r'$10^4$'], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# plt.figure(figsize=(8,6))
# # Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_n.pdf", format="pdf", bbox_inches="tight")
plt.clf()


## Memory
bar_width = 0.9
n_positions = np.arange(len(n))
plt.bar(n_positions - bar_width/3, bl_mem, width=bar_width/3, color='b', label='Baseline')
plt.bar(n_positions, st_mem, width=bar_width/3, color='skyblue', label='RPM-ST')
plt.bar(n_positions + bar_width/3, esa_mem, width=bar_width/3, color='orange', label='RPM-ESA')
plt.ylim(1, 10000)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.yscale('log')
plt.xlabel(r"$n$", fontsize=30)
plt.ylabel("Memory (MB)", fontsize=30)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.03, 1.04), fontsize=25)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
plt.legend(bbox_to_anchor=(1.04, 1.26), ncol=3, columnspacing=0.5, handletextpad=0.2, fontsize = 23)
plt.xticks(n_positions, [5000,10000,20000,50000,100000], fontsize=30, rotation=45)
plt.yticks(fontsize=30)

plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_n.pdf", format="pdf", bbox_inches="tight")
plt.clf()


