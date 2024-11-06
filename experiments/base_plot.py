import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


# ## Change tau
# df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_tau.csv")
# n = []
# tau = []
# k = []
# bl_runtime = []
# main_runtime = []
# bl_mem = []
# main_mem = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     bl_mem.append(row['bl_mem'] / 1000)
#     main_mem.append(row['main_mem'] / 1000)

#     bl_runtime.append(row['bl_time (s)'])
#     main_runtime.append(row['main_time (s)'])


# ## Runtime
# bar_width = 0.4
# n_positions = np.arange(len(tau))
# plt.bar(n_positions - bar_width/2, bl_runtime, width=bar_width, color='b', label='Baseline')
# plt.bar(n_positions + bar_width/2, main_runtime, width=bar_width, color='r', label='RPM-ST')
# # plt.ylim(1, pow(10,2))
# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.yscale('log')
# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
# plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_tau.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

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
# df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_k.csv")
# n = []
# tau = []
# k = []
# bl_runtime = []
# main_runtime = []
# bl_mem = []
# main_mem = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     bl_mem.append(row['bl_mem'] / 1000)
#     main_mem.append(row['main_mem'] / 1000)

#     bl_runtime.append(row['bl_time (s)'])
#     main_runtime.append(row['main_time (s)'])

# ## Runtime
# bar_width = 0.4
# n_positions = np.arange(len(k))
# plt.bar(n_positions - bar_width/2, bl_runtime, width=bar_width, color='b', label='Baseline')
# plt.bar(n_positions + bar_width/2, main_runtime, width=bar_width, color='r', label='RPM-ST')
# # plt.ylim(1, pow(10,2))
# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.yscale('log')
# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
# plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_k.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# ## Memory
# bar_width = 0.4
# n_positions = np.arange(len(k))
# plt.bar(n_positions - bar_width/2, bl_mem, width=bar_width, color='b', label='Baseline')
# plt.bar(n_positions + bar_width/2, main_mem, width=bar_width, color='r', label='RPM-ST')
# # plt.ylim(1, pow(10,5))
# # plt.ylim(0, max(bl_mem) + 1000)
# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# # plt.yscale('log')
# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("memory (MB)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
# plt.xticks(n_positions, [5, 10, 20, 50, 100], fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_k.pdf", format="pdf", bbox_inches="tight")
# plt.clf()




## Change n
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Baseline/change_n.csv")
n = []
tau = []
k = []
bl_runtime = []
main_runtime = []
bl_mem = []
main_mem = []

for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    bl_mem.append(row['bl_mem'] / 1000)
    main_mem.append(row['main_mem'] / 1000)

    bl_runtime.append(row['bl_time (s)'])
    main_runtime.append(row['main_time (s)'])

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


print(n)
print(bl_mem)
print(bl_runtime)
print(main_mem)
print(main_runtime)

## Runtime
bar_width = 0.4
n_positions = np.arange(len(n))
plt.bar(n_positions - bar_width/2, bl_runtime, width=bar_width, color='b', label='Baseline')
plt.bar(n_positions + bar_width/2, main_runtime, width=bar_width, color='r', label='RPM-ST')
# plt.ylim(1, pow(10,2))
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale('log')
plt.yscale('log')
plt.xlabel(r"$n$", fontsize=30)
plt.ylabel("runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
plt.xticks(n_positions, [1000,2000,5000,10000,20000], fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# plt.figure(figsize=(8,6))
# # Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_time_n.pdf", format="pdf", bbox_inches="tight")
plt.clf()


## Memory
bar_width = 0.4
n_positions = np.arange(len(k))
plt.bar(n_positions - bar_width/2, bl_mem, width=bar_width, color='b', label='Baseline')
plt.bar(n_positions + bar_width/2, main_mem, width=bar_width, color='r', label='RPM-ST')
# plt.ylim(1, pow(10,5))
# plt.ylim(0, max(bl_mem) + 1000)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale('log')
plt.xlabel(r"$n$", fontsize=30)
plt.ylabel("memory (MB)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
plt.legend(bbox_to_anchor=(1.03, 1.25), ncol=2, fontsize = 28)
plt.xticks(n_positions, [1000,2000,5000,10000,20000], fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/bl_mem_n.pdf", format="pdf", bbox_inches="tight")
plt.clf()
