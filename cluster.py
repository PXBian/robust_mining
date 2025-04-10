import pandas as pd
from sklearn.cluster import KMeans
from sklearn.metrics import rand_score, homogeneity_score, normalized_mutual_info_score
import argparse
import numpy as np

def main():
    parser = argparse.ArgumentParser(description='K-means clustering and evaluation.')
    parser.add_argument('features', type=str, help='Path to normalized_matrix.csv')
    parser.add_argument('labels', type=str, help='Path to ground_truth_label.csv')
    parser.add_argument('seed', type=int, help='Random seed for KMeans')
    parser.add_argument('tau', type=int, help='threshold')
    parser.add_argument('k', type=int, help='number of substitution')
    parser.add_argument('K', type=int, help='top-K global frequent patterns as features')
    parser.add_argument('output', type=str, help='Path to output file')

    args = parser.parse_args()

    # Load feature matrix
    tau=args.tau
    k=args.k
    K=args.K
    df_features = pd.read_csv(args.features)
    X = df_features.drop(columns=['Sample']).values  # drop the sample index column

    # Load ground truth labels
    df_labels = pd.read_csv(args.labels)
    true_labels = df_labels['ClusterLabel'].values  # assumes columns are "Sample,label"

    # Set number of clusters to the number of unique ground truth labels
    n_clusters = len(np.unique(true_labels))

    # Run KMeans
    kmeans = KMeans(n_clusters=n_clusters, init='k-means++', n_init=10, random_state=args.seed)
    kmeans.fit(X)
    predicted_labels = kmeans.labels_

    # Evaluation
    nmi = normalized_mutual_info_score(true_labels, predicted_labels)
    ri = rand_score(true_labels, predicted_labels)
    homogeneity = homogeneity_score(true_labels, predicted_labels)

    print(f"NMI: {nmi:.4f}")
    print(f"Homogeneity: {homogeneity:.4f}")
    print(f"Rand Index (RI): {ri:.4f}")

    # Optional: Print cluster membership
    print(f"\n{X.shape[1]} features are used. n_clusters is set to {n_clusters}")
    cluster_dict = {}
    for cluster_idx in range(n_clusters):
        instances = np.where(predicted_labels == cluster_idx)[0]
        cluster_dict[cluster_idx] = instances
        print(f"Cluster {cluster_idx+1} has instances: {instances + 1}")  # add 1 to match Sample ID

    result_data = {
        'tau': tau,
        'k': k,
        'Top_K': K,
        'NMI': nmi,
        'Homogeneity': homogeneity,
        'RI': ri
    }
    # Append the result to the CSV file
    result_df = pd.DataFrame([result_data])
    output_file = args.output
    result_df.to_csv(output_file, mode='a', header=not pd.io.common.file_exists(output_file), index=False)

if __name__ == '__main__':
    main()
