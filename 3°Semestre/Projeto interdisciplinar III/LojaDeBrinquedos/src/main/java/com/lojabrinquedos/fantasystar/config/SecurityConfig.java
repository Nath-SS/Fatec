// package com.lojabrinquedos.fantasystar.config;

// import org.springframework.context.annotation.Bean;
// import org.springframework.context.annotation.Configuration;
// import org.springframework.security.config.annotation.web.builders.HttpSecurity;
// import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
// import org.springframework.security.web.SecurityFilterChain;


// @Configuration
// @EnableWebSecurity
// public class SecurityConfig {

//     @Bean
//     SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
// 		http
// 			.authorizeHttpRequests((requests) -> requests
// 				.requestMatchers("/*", "/user/*", "/css/**","/js/**", "/images/**").permitAll() //mappings q devem ser publicos
//                 .requestMatchers("/administracao/**").hasRole("ADM") //mappings q requer função de adm
// 				.anyRequest().authenticated() //qualquer outro além disso requer autorização
// 			)
// 			.formLogin((form) -> form
// 				.loginPage("/user/login") //define a página de login permitida para todos
//                 .loginProcessingUrl("/user/login")
//                 .defaultSuccessUrl("/")
// 				.permitAll()
// 			)
// 			.logout((logout) -> logout
//                 .logoutUrl("/logout") //define a url de logout para todos
//                 .logoutSuccessUrl("/login")
//                 .permitAll()
//             );

// 		return http.build();
// 	}

// }
