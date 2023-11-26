function toggleModoEscuro() {
    // Obtém o estado atual do modo escuro do localStorage
    var modoEscuroAtivo = localStorage.getItem('modoEscuro') === 'true';

    // Inverte o estado
    modoEscuroAtivo = !modoEscuroAtivo;

    // Atualiza o estado no localStorage
    localStorage.setItem('modoEscuro', modoEscuroAtivo);

    // Atualiza a folha de estilo com base no estado
    var estilo = document.getElementById('style');
    estilo.setAttribute('href', modoEscuroAtivo ? '/css/style-escuro.css' : '/css/style.css');
}

function aplicarModoEscuro() {
    var modoEscuroAtivo = localStorage.getItem('modoEscuro') === 'true';
    var estilo = document.getElementById('style');
    estilo.setAttribute('href', modoEscuroAtivo ? '/css/style-escuro.css' : '/css/style.css');
}