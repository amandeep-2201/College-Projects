SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `contact_form` (
  `id` int(100) NOT NULL,
  `name` varchar(50) NOT NULL,
  `age` varchar(3) NOT NULL,
  `gender` varchar(10) NOT NULL,
  `number` varchar(10) NOT NULL,
  `email` varchar(100) NOT NULL,
  `problem` varchar(255) NOT NULL,
  `date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

ALTER TABLE `contact_form`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `contact_form`
  MODIFY `id` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;
