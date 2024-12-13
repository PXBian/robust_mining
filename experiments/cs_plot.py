import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np


# Change tau
df = pd.read_csv("/home/pengxinbian/Desktop/experiment/Casestudy/sars_plot_tau.csv")
n = []
tau = []
k = []
time_CS = []
time_ST = []
resi_jacc = []
freq_jacc = []


for index, row in df.iterrows():
    tau.append(row['tau'])
    k.append(row['k'])
    time_CS.append(row['time_CS'])
    time_ST.append(row['time_ST'])
    resi_jacc.append(row['resi_jacc_ratio'])
    freq_jacc.append(row['freq_jacc_ratio'])

# Runtime
fig, ax = plt.subplots(figsize=(12, 4))
bar_width = 0.4
n_positions = np.arange(len(tau))
plt.bar(n_positions - bar_width/2, time_ST, width=bar_width, color='lightgreen', label='RPM-ST')
plt.bar(n_positions + bar_width/2, time_CS, width=bar_width, color='seagreen', label='FI')
# plt.ylim(0.01, pow(10,8))
# plt.ylim(0, max(time_CS) + 100)

# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
plt.yscale('log')
plt.xlabel(r"$\tau=k$", fontsize=32)
plt.ylabel("Runtime (s)", fontsize=32)
# plt.legend(loc='best', fontsize=28)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.03, 1.04), fontsize=27)
plt.legend(bbox_to_anchor=(0.8, 1.35), ncol=2, columnspacing=0.8, handletextpad=0.5, fontsize = 32)
# plt.xticks(n_positions, [25,50,75,100,125,150,175,200], fontsize=30, rotation=45)
plt.xticks(n_positions, [150,200,250,300,500,600,700,800,900], fontsize=32)
ticks = [10**-2, 10**0, 10**2, 10**4]
plt.yticks(ticks, [r'$10^{-2}$', r'$10^0$', r'$10^2$', r'$10^4$'], fontsize=32)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/casestudy_time.pdf", format="pdf", bbox_inches="tight")
plt.clf()


# Jaccard
fig, ax = plt.subplots(figsize=(12, 4))
bar_width = 0.4
n_positions = np.arange(len(tau))
plt.bar(n_positions - bar_width/2, resi_jacc, width=bar_width, color='bisque', label=r"$J_R$")
plt.bar(n_positions + bar_width/2, freq_jacc, width=bar_width, color='orange', label=r"$J_F$")
# plt.ylim(1, pow(10,5))
# plt.ylim(0, 1.6)

# plt.gca().yaxis.get_major_formatter().set_useOffset(False)
# plt.gca().yaxis.get_major_formatter().set_scientific(False)
# plt.yscale('log')
plt.xlabel(r"$\tau=k$", fontsize=32)
plt.ylabel("Jaccard Similarity", fontsize=32)
# plt.legend(loc='best', fontsize=28)
# plt.legend(loc='upper left', bbox_to_anchor=(-0.03, 1.04), fontsize=27)
plt.legend(bbox_to_anchor=(0.72, 1.35), ncol=2, columnspacing=0.8, handletextpad=0.5, fontsize = 32)
# plt.xticks(n_positions, [25,50,75,100,125,150,175,200], fontsize=30, rotation=45)
plt.xticks(n_positions, [150,200,250,300,500,600,700,800,900], fontsize=32)
plt.yticks([0,0.2,0.4,0.6,0.8,1.0], fontsize=32)
plt.grid(True, linestyle='--', linewidth=0.5)
# Adjust the layout to be tight
# plt.tight_layout()
# plt.show()
plt.savefig("/home/pengxinbian/Desktop/ex_plots/casestudy_jacc.pdf", format="pdf", bbox_inches="tight")
plt.clf()
