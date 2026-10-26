# ==========================================
# 1. TẦNG HUẤN LUYỆN & LƯỢNG TỬ HÓA (Python Layer)
# ==========================================
import torch
import torch.nn as nn

class EdgeClassifier(nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super(EdgeClassifier, self).__init__()
        self.fc1 = nn.Linear(input_dim, hidden_dim)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_dim, output_dim)

    def forward(self, x):
        return self.fc2(self.relu(self.fc1(x)))

if __name__ == "__main__":
    print("Mô hình mẫu sẵn sàng cho việc huấn luyện và xuất trọng số fixed-point.")
