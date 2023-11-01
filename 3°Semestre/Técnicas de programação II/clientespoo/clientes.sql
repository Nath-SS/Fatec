--
-- Database: `meubancodedados`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `clientes`
--

CREATE TABLE `clientes` (
  `codcliente` int(11) primary key auto_increment NOT NULL,
  `Nome` varchar(100) DEFAULT NULL,
  `Email` varchar(100) DEFAULT NULL,
  `DataNascimento` date DEFAULT NULL,
  `RG` varchar(15) DEFAULT NULL,
  `CPF` varchar(15) DEFAULT NULL,
  `Endereco` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

