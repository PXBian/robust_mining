import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


# Change tau
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_tau_source200.csv")
n = []
tau = []
k = []
time_ESA = []
time_ST = []
mem_ESA = []
mem_ST = []
qua = []

for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    mem_ESA.append(row['mem_ESA'] / 1000000)
    mem_ST.append(row['mem_ST'] / 1000000)
    time_ESA.append(row['time_ESA'])
    time_ST.append(row['time_ST'])
    qua.append(row['ratio'])

log_tau = np.log10(tau)
log_k = np.log10(k)


## Runtime
fig, ax = plt.subplots(figsize=(11, 4))
width_set = 10
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
# plt.ylim(0, max(time_ST) + 400)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_bar = np.diff(tau + [tau[-1] * 10]) / 11
widths_offset = np.diff(tau + [tau[-1] * 10]) / 6
# print(widths_esa)
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
plt.bar(tau, time_ST, widths_bar, color='skyblue', label = 'RPM-ST')
plt.bar(tau+widths_offset/1.2, time_ESA, widths_bar*2, color='royalblue', label = 'RPM-ESA')

plt.xlabel(r"$\tau$", fontsize=32)
plt.ylabel("Runtime (s)", fontsize=32)
plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), ncol = 2, fontsize=30)
plt.xticks(fontsize=32)
plt.yticks([0,600,1200,1800],fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_tau_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# # Memory
fig, ax = plt.subplots(figsize=(11, 4))
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
# plt.ylim(0, max(mem_ST) + 40)
# plt.ylim(0, 110)

plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_bar = np.diff(tau + [tau[-1] * 10]) / 11
widths_offset = np.diff(tau + [tau[-1] * 10]) / 6
# print(widths_esa)
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
plt.bar(tau, mem_ST, widths_bar, color='plum', label = 'RPM-ST')
plt.bar(tau+widths_offset/1.2, mem_ESA, widths_bar*2, color='purple', label = 'RPM-ESA')

plt.xlabel(r"$\tau$", fontsize=32)
plt.ylabel("Memory (GB)", fontsize=32)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.03), fontsize=27)
plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), ncol = 2, fontsize=30)
plt.xticks(fontsize=32)
plt.yticks([0,20,40,60,80,100], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()

plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_mem_tau_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()


## Quality
fig, ax = plt.subplots(figsize=(11, 4))
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
plt.ylim(0, max(qua) + 0.5)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_st = np.diff(tau + [tau[-1] * 10]) / 11
# widths_esa = np.diff(tau + [tau[-1] * 10]) / 8
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
bars=plt.bar(tau, qua, widths_st, color='green', label = 'RPM-ST/ESA')
# plt.bar(tau, qua, widths_esa, color='red', label = 'RPM-ESA')

plt.xlabel(r"$\tau$", fontsize=32)
plt.ylabel("Quality", fontsize=32)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.03), fontsize=27)
# plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), fontsize=27)
plt.legend(loc='upper left', bbox_to_anchor=(-0.02, 1.05), fontsize=30)
plt.xticks(fontsize=32)
plt.yticks([],fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

ax.bar_label(bars, fmt='%.2f', padding=3, fontsize=29)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_qua_tau_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()


## Change k
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_k_source200.csv")
n = []
tau = []
k = []
time_ESA = []
time_ST = []
mem_ESA = []
mem_ST = []
qua = []

for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    mem_ESA.append(row['mem_ESA'] / 1000000)
    mem_ST.append(row['mem_ST'] / 1000000)
    time_ESA.append(row['time_ESA'])
    time_ST.append(row['time_ST'])
    qua.append(row['ratio'])


## Runtime
fig, ax = plt.subplots(figsize=(11, 4))
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
# plt.ylim(0, max(time_ST) + 700)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_bar = np.diff(k + [k[-1] * 10]) / 11
widths_offset = np.diff(k + [k[-1] * 10]) / 6
# print(widths_esa)
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
plt.bar(k, time_ST, widths_bar, color='skyblue', label = 'RPM-ST')
plt.bar(k+widths_offset/1.2, time_ESA, widths_bar*2, color='royalblue', label = 'RPM-ESA')

plt.xlabel(r"$k$", fontsize=32)
plt.ylabel("Runtime (s)", fontsize=32)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.03), fontsize=27)
plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), ncol = 2, fontsize=30)
plt.xticks(fontsize=32)
plt.yticks([0,600,1200,1800], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_k_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# # Memory
fig, ax = plt.subplots(figsize=(11, 4))
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
# plt.ylim(0, max(mem_ST) + 40)
# plt.ylim(0, 110)

plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_bar = np.diff(k + [k[-1] * 10]) / 11
widths_offset = np.diff(k + [k[-1] * 10]) / 6
# print(widths_esa)
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
plt.bar(k, mem_ST, widths_bar, color='plum', label = 'RPM-ST')
plt.bar(k+widths_offset/1.2, mem_ESA, widths_bar*2, color='purple', label = 'RPM-ESA')

plt.xlabel(r"$k$", fontsize=32)
plt.ylabel("Memory (GB)", fontsize=32)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.03), fontsize=27)
plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), ncol = 2, fontsize=30)
plt.xticks(fontsize=32)
plt.yticks([0,20,40,60,80,100], fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()

plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_mem_k_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()



## Quality
fig, ax = plt.subplots(figsize=(11, 4))
plt.gca().xaxis.set_major_formatter(ScalarFormatter())
plt.ticklabel_format(style='plain')
plt.ylim(0, max(qua) + 0.2)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.xscale("log")
widths_st = np.diff(k + [k[-1] * 10]) / 11
# widths_esa = np.diff(k + [k[-1] * 10]) / 8
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')
bars = plt.bar(k, qua, widths_st, color='green', label = 'RPM-ST/ESA')
# plt.bar(k, qua, widths_esa, color='red', label = 'RPM-ESA')

plt.xlabel(r"$k$", fontsize=32)
plt.ylabel("Quality", fontsize=32)
# plt.legend(loc='upper right', bbox_to_anchor=(1.03, 1.03), fontsize=27)
plt.legend(loc='upper right', bbox_to_anchor=(1.02, 1.05), fontsize=29)
plt.xticks(fontsize=32)
plt.yticks([],fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)

ax.bar_label(bars, fmt='%.2f', padding=3, fontsize=32)

# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_qua_k_source200.pdf", format="pdf", bbox_inches="tight")
plt.clf()



## Change n
# df = pd.read_csv("/home/pengxinbian/Desktop/experiment/ST_ESA/change_n_source200.csv")
# n = []
# time_ST = []
# time_ESA = []
# mem_ST = []
# mem_ESA = []

# for index, row in df.iterrows():
#     time_ST.append(row['time_ST'])
#     time_ESA.append(row['time_ESA'])
#     mem_ST.append(row['mem_ST']/ 1000000) 
#     mem_ESA.append(row['mem_ESA'] / 1000000) 

#     if(row['text_file'] == 'data/dna.200MB_25MB'):
#         n.append(25)
#     elif(row['text_file'] == 'data/dna.200MB_50MB'):
#         n.append(50)
#     elif(row['text_file'] == 'data/dna.200MB_75MB'):
#         n.append(75)
#     elif(row['text_file'] == 'data/dna.200MB_100MB'):
#         n.append(100)
#     elif(row['text_file'] == 'data/dna.200MB_125MB'):
#         n.append(125)
#     elif(row['text_file'] == 'data/dna.200MB_150MB'):
#         n.append(150)
#     elif(row['text_file'] == 'data/dna.200MB_175MB'):
#         n.append(175)
#     elif(row['text_file'] == 'data/dna.200MB'):
#         n.append(200)

# # Runtime
# fig, ax = plt.subplots(figsize=(10, 4))
# bar_width = 0.4
# n_positions = np.arange(len(n))
# plt.bar(n_positions - bar_width/2, time_ST, width=bar_width, color='skyblue', label='RPM-ST')
# plt.bar(n_positions + bar_width/2, time_ESA, width=bar_width, color='royalblue', label='RPM-ESA')
# # plt.ylim(1, pow(10,5))
# plt.ylim(0, max(time_ST) + 100)

# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# # plt.yscale('log')
# plt.xlabel(r"$n$ (MB)", fontsize=30)
# plt.ylabel("Runtime (s)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.02, 1.05), ncol = 2, fontsize=27)
# plt.xticks(n_positions, [25,50,75,100,125,150,175,200], fontsize=30)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_time_n_source200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# # Memory
# fig, ax = plt.subplots(figsize=(10, 4))
# bar_width = 0.4
# n_positions = np.arange(len(n))
# plt.bar(n_positions - bar_width/2, mem_ST, width=bar_width, color='plum', label='RPM-ST')
# plt.bar(n_positions + bar_width/2, mem_ESA, width=bar_width, color='purple', label='RPM-ESA')
# # plt.ylim(1, pow(10,5))
# # plt.ylim(0, max(mem_ST) + 10)

# # plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# # plt.gca().yaxis.get_major_formatter().set_scientific(False)
# # plt.yscale('log')
# plt.xlabel(r"$n$ (MB)", fontsize=30)
# plt.ylabel("Memory (GB)", fontsize=30)
# # plt.legend(loc='best', fontsize=28)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.02, 1.05), ncol = 2, fontsize=27)
# plt.xticks(n_positions, [25,50,75,100,125,150,175,200], fontsize=30)
# plt.yticks([0,20,40,60,80], fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/effi_mem_n_source200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

