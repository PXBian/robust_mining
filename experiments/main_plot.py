import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


## Change k
# df = pd.read_csv("change_k_dna200.csv")


# tau = []
# k = []
# space = []
# runtime = []
# quality = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     space.append(row['Max RSS (kB)'] / 1000000)
#     runtime.append(row['runtime (s)'])
#     quality.append(row['ratio'])


# ## Runtime
# # plt.plot(k, runtime, linewidth=5, marker = 'o', markersize=10, color = 'red', linestyle = '--', label = 'RPM-ST')
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(runtime) + 500)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths = np.diff(k + [k[-1] * 10])
# plt.bar(k, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/time_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

# ## Space
# # plt.plot(k, space, linewidth=5, marker = '^', markersize=10, color = 'orange', linestyle = '--', label = 'RPM-ST')
# # plt.bar(k, space, color = 'orange', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(space) + 40)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths = np.diff(k + [k[-1] * 10])
# plt.bar(k, space, widths, align='edge', facecolor='orange', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("memory (GB)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/mem_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

# ## Quality
# # plt.plot(k, quality, linewidth=5, marker = '*', markersize=10, color = 'green', linestyle = '--', label = 'RPM-ST')
# # plt.bar(k, quality, color = 'green', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.xscale("log")
# plt.ylim(0, max(quality) + 0.5)
# widths = np.diff(k + [k[-1] * 10])
# plt.bar(k, quality, widths, align='edge', facecolor='green', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$k$", fontsize=30)
# plt.ylabel("ratio", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/qua_k_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


# ## Change tau
# df = pd.read_csv("change_tau_dna200.csv")

# tau = []
# k = []
# space = []
# runtime = []
# quality = []

# for index, row in df.iterrows():
#     tau.append(row['tau'])
#     k.append(row['k'])
#     space.append(row['Max RSS (kB)'] / 1000000)
#     runtime.append(row['runtime (s)'])
#     quality.append(row['ratio'])

# ## Runtime
# # plt.plot(tau, runtime, linewidth=5, marker = 'o', markersize=10, color = 'red', linestyle = '--', label = 'RPM-ST')
# # plt.bar(tau, runtime, color = 'red', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(runtime) + 200)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths = np.diff(tau + [tau[-1] * 10])
# plt.bar(tau, runtime, widths, align='edge', facecolor='red', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("runtime (s)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/time_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

# ## Space
# # plt.plot(tau, space, linewidth=5, marker = '^', markersize=10, color = 'orange', linestyle = '--', label = 'RPM-ST')
# # plt.bar(tau, space, color = 'orange', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.ylim(0, max(space) + 40)
# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.xscale("log")
# widths = np.diff(tau + [tau[-1] * 10])
# plt.bar(tau, space, widths, align='edge', facecolor='orange', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("memory (GB)", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/mem_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()

# ## Quality
# # plt.plot(tau, quality, linewidth=5, marker = '*', markersize=10, color = 'green', linestyle = '--', label = 'RPM-ST')
# # plt.bar(tau, quality, color = 'green', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
# plt.xscale("log")
# plt.ylim(0, max(quality) + 0.5)
# widths = np.diff(tau + [tau[-1] * 10])
# plt.bar(tau, quality, widths, align='edge', facecolor='green', edgecolor='white', lw=2, label = 'RPM-ST')

# plt.xlabel(r"$\tau$", fontsize=30)
# plt.ylabel("ratio", fontsize=30)
# plt.legend(loc='best', fontsize=28)
# plt.xticks(fontsize=30, rotation=45)
# plt.yticks(fontsize=30)
# plt.grid(True, linestyle='--', linewidth=0.5)
# # Adjust the layout to be tight
# # plt.tight_layout()
# # plt.show()
# plt.savefig("/home/pengxinbian/Desktop/ex_plots/qua_tau_dna200.pdf", format="pdf", bbox_inches="tight")
# plt.clf()


## Change n
df = pd.read_csv("change_n_dna200.csv")
n = []
runtime = []

for index, row in df.iterrows():
    runtime.append(row['runtime (s)'])
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
plt.bar(n, runtime, color = 'skyblue', label = 'RPM-ST', width = 30)
# plt.gca().xaxis.set_major_formatter(ScalarFormatter())
# plt.ticklabel_format(style='plain')
plt.ylim(0, max(runtime) + 200)
plt.gca().yaxis.get_major_formatter().set_useOffset(False)
plt.gca().yaxis.get_major_formatter().set_scientific(False)

plt.xlabel(r"$n$ (MB)", fontsize=30)
plt.ylabel("runtime (s)", fontsize=30)
plt.legend(loc='best', fontsize=28)
plt.xticks(n, fontsize=30, rotation=45)
plt.yticks(fontsize=30)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/time_n_dna200.pdf", format="pdf", bbox_inches="tight")
