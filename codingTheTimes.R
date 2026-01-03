# Setup
rm(list = ls(all.names = TRUE))
options(scipen = 999) 
library(ggplot2)
library(scales) 

# Input data (Manual input Because CSV'S cant do anything )
input_size <- c(10, 100, 500, 1000, 2500, 5000, 7500, 10000)
lin_iter <- c(0.000533, 0.001300, 0.007067, 0.013933, 0.029700, 0.037300, 0.066167, 0.090300)
lin_recur <- c(0.000400, 0.002100, 0.031800, 0.054233, 0.133267, 0.110300, 0.195667, 0.238733)
bin_iter <- c(0.000233, 0.000333, 0.000367, 0.000400, 0.000467, 0.000400, 0.000400, 0.000533)
bin_recur <- c(0.000333, 0.000333, 0.000433, 0.000400, 0.000400, 0.000467, 0.000433, 0.000500)

df <- data.frame(input_size, lin_iter, lin_recur, bin_iter, bin_recur)

# Graph Number 1... (Linear Searches)
ggplot(df) +
  geom_line(aes(x = input_size, y = lin_iter, color = "Iterative"), linewidth = 1) +
  geom_point(aes(x = input_size, y = lin_iter, color = "Iterative")) +
  geom_line(aes(x = input_size, y = lin_recur, color = "Recursive"), linewidth = 1) +
  geom_point(aes(x = input_size, y = lin_recur, color = "Recursive")) +
  scale_y_continuous(labels = label_number(accuracy = 0.0001), limits = c(0, 0.40)) + 
  labs(title = "Linear Search Performance: O(n)",
       x = "Input Size (n)", y = "Running Time (ms)", color = "Color") +
  theme_minimal() +
  scale_color_manual(values = c("Iterative" = "blue", "Recursive" = "red"))

# Graph number 2... (Binary Searches)
ggplot(df) +
  geom_line(aes(x = input_size, y = bin_iter, color = "Iterative"), linewidth = 1) +
  geom_point(aes(x = input_size, y = bin_iter, color = "Iterative")) +
  geom_line(aes(x = input_size, y = bin_recur, color = "Recursive"), linewidth = 1) +
  geom_point(aes(x = input_size, y = bin_recur, color = "Recursive")) +
  scale_y_continuous(labels = label_number(accuracy = 0.00001), limits = c(0, 0.0015)) + # 5 decimals
  labs(title = "Binary Search Performance: O(log n)",
       x = "Input Size (n)", y = "Running Time (ms)", color = "Color") +
  theme_minimal() +
  scale_color_manual(values = c("Iterative" = "darkgreen", "Recursive" = "orange"))

#Im loosing myself.....
