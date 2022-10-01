-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 05, 2021 at 02:01 PM
-- Server version: 10.4.17-MariaDB
-- PHP Version: 8.0.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bank`
--

-- --------------------------------------------------------

--
-- Table structure for table `customers`
--

CREATE TABLE `customers` (
  `Id` int(50) NOT NULL,
  `name` varchar(200) NOT NULL,
  `email` varchar(100) NOT NULL,
  `amount` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `customers`
--

INSERT INTO `customers` (`Id`, `name`, `email`, `amount`) VALUES
(1, 'Asad', 'asad@gmail.com', '9000'),
(2, 'Rakib', 'rakib@gmail.com', '4000'),
(3, 'Topu', 'topu@gmail.com', '3000'),
(4, 'Asma', 'asma@gmail.com', '3000'),
(5, 'Sifa', 'sifa@gmail.com', '9000'),
(6, 'Azan', 'azan@gmail.com', '6800'),
(7, 'Rahim', 'rahim@gmail.com', '2100'),
(8, 'Kabir', 'kabir@gmail.com', '500'),
(9, 'Jhon', 'jhon@gmail.com', '2000'),
(10, 'Priyanka', 'priyanka@gmail.com', '2500');

-- --------------------------------------------------------

--
-- Table structure for table `transfer_money`
--

CREATE TABLE `transfer_money` (
  `id` int(50) NOT NULL,
  `sender` varchar(200) NOT NULL,
  `receiver` varchar(200) NOT NULL,
  `amount` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transfer_money`
--

INSERT INTO `transfer_money` (`id`, `sender`, `receiver`, `amount`) VALUES
(12, 'Asma', 'Sifa', '2000'),
(14, 'Asad', 'Rakib', '1000'),
(15, 'Asad', 'Rakib', '1000'),
(16, 'Azan', 'Rahim', '2000');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customers`
--
ALTER TABLE `customers`
  ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `transfer_money`
--
ALTER TABLE `transfer_money`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customers`
--
ALTER TABLE `customers`
  MODIFY `Id` int(50) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `transfer_money`
--
ALTER TABLE `transfer_money`
  MODIFY `id` int(50) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
