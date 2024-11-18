import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


# # Change tau
# df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_tau_dna200.csv")
# n = []
# tau = []
# k = []
# time_ESA = []
# time_ST = []
# mem_ESA = []
# mem_ST = []
# qua = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     mem_ESA.append(row['mem_ESA'] / 1000000)
#     mem_ST.append(row['mem_ST'] / 1000000)
#     time_ESA.append(row['time_ESA'])
#     time_ST.append(row['time_ST'])
#     qua.append(row['ratio'])


# ## Runtime
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(time_ST) + 600)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(tau + [tau[-1] * 10]) / 8
# widths_esa = np.diff(tau + [tau[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(tau, time_ST, widths_st, color='yellow', label = 'RPM-ST')
# plt.bar(tau, time_ESA, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# # # Memory
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(mem_ST) + 40)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(tau + [tau[-1] * 10]) / 8
# widths_esa = np.diff(tau + [tau[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(tau, mem_ST, widths_st, color='yellow', label = 'RPM-ST')
# plt.bar(tau, mem_ESA, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("memory (GB)", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()

# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_mem_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# ## Quality
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(qua) + 0.3)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(tau + [tau[-1] * 10]) / 8
# widths_esa = np.diff(tau + [tau[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(tau, qua, widths_st, color='green', label = 'RPM-ST/ESA')
# # plt.bar(tau, qua, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("quality", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_qua_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# ## Change k
# df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_k_dna200.csv")
# n = []
# tau = []
# k = []
# time_ESA = []
# time_ST = []
# mem_ESA = []
# mem_ST = []
# qua = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     mem_ESA.append(row['mem_ESA'] / 1000000)
#     mem_ST.append(row['mem_ST'] / 1000000)
#     time_ESA.append(row['time_ESA'])
#     time_ST.append(row['time_ST'])
#     qua.append(row['ratio'])



# ## Runtime
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(time_ST) + 700)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(k + [k[-1] * 10]) / 8
# widths_esa = np.diff(k + [k[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(k, time_ST, widths_st, color='yellow', label = 'RPM-ST')
# plt.bar(k, time_ESA, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# # # Memory
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(mem_ST) + 40)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(k + [k[-1] * 10]) / 8
# widths_esa = np.diff(k + [k[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(k, mem_ST, widths_st, color='yellow', label = 'RPM-ST')
# plt.bar(k, mem_ESA, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("memory (GB)", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()

# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_mem_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()



# ## Quality
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(qua) + 0.3)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths_st = np.diff(k + [k[-1] * 10]) / 8
# widths_esa = np.diff(k + [k[-1] * 10]) / 8
# # plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
# plt.bar(k, qua, widths_st, color='green', label = 'RPM-ST/ESA')
# # plt.bar(k, qua, widths_esa, color='red', label = 'RPM-ESA')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("quality", fontsize=30)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.04), fontsize=27)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_qua_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()



## Change n
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_n_dna200.csv")
n = []
time_ST = []
time_ESA = []

for index, row in df.iterrows():
    time_ST.append(row['time_ST'])
    time_ESA.append(row['time_ESA'])

    if(row['text_file'] == 'data/dna.200MB_25MB'):
        n.append(25)
    elif(row['text_file'] == 'data/dna.200MB_50MB'):
        n.append(50)
    elif(row['text_file'] == 'data/dna.200MB_75MB'):
        n.append(75)
    elif(row['text_file'] == 'data/dna.200MB_100MB'):
        n.append(100)
    elif(row['text_file'] == 'data/dna.200MB_125MB'):
        n.append(125)
    elif(row['text_file'] == 'data/dna.200MB_150MB'):
        n.append(150)
    elif(row['text_file'] == 'data/dna.200MB_175MB'):
        n.append(175)
    elif(row['text_file'] == 'data/dna.200MB'):
        n.append(200)

## Runtime
# plt.plot(n, runtime, linewidth=5, marker = 'o', markersize=10, color = 'red', linestyle = '--', label = 'RPM-ST')
# plt.bar(n, runtime, edgecolor = 'skyblue', facecolor='none', label = 'RPM-ST', width = 20)
plt.bar(n, time_ST, color = 'yellow', label = 'RPM-ST', width = 20)
plt.bar(n, time_ESA, color = 'red', label = 'RPM-ESA', width = 20)

# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
plt.ylim(0, max(time_ST) + 200)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)

plt.xlabel(r"$n$ (MB)", fontsize=30)
plt.ylabel("runtime (s)", fontsize=30)
plt.legend(loc='upper left', bbox_to_anchor=(-0.03, 1.04), fontsize=27)
plt.xticks(n, fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_n_dna200.pdf", format="pdf", bbox_inches="tight")
