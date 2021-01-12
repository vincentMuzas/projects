<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class MainController extends AbstractController
{
    /**
     * @Route("/", name="main")
     */
    public function index(): Response
    {
        return $this->render('index.html.twig', [
            'controller_name' => 'MainController',
        ]);
    }

    /**
     * @Route("/register")
     */
    public function register(): Response
    {
        return $this->render('register.html.twig');
    }

    /**
     * @Route("/login")
     */
    public function flogin(): Response
    {
        return $this->render('login.html.twig');
    }
}
