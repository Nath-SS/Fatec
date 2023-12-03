package com.lojabrinquedos.fantasystar.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.web.SecurityFilterChain;
import com.lojabrinquedos.fantasystar.service.UserService;



@Configuration
@EnableWebSecurity
public class SecurityConfig  {

    @Autowired
    private UserService userService;

    @Autowired
    private BCryptPasswordEncoder encoder;

    
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.userDetailsService(userService).passwordEncoder(encoder);
    }

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
		http
			.authorizeHttpRequests((requests) -> requests
				.requestMatchers("/*", "/user/*", "/css/**","/js/**", "/images/**").permitAll() //mappings q devem ser publicos
                .requestMatchers("/administracao/**").hasRole("ADM") //mappings q requer função de adm
				.anyRequest().authenticated() //qualquer outro além disso requer autorização
			)
			.formLogin((form) -> form
				.loginPage("/user/login") //define a página de login permitida para todos
				.permitAll()
			)
			.logout((logout) -> logout
                .logoutUrl("/user/logout") //define a url de logout para todos
                .permitAll()
            );

		return http.build();
	}

}
