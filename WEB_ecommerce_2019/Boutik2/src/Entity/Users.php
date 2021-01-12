<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use ApiPlatform\Core\Annotation\ApiResource;
/**
 * Users
 *
 * @ORM\Table(name="users")
 * @ORM\Entity
 */
/**
 * ...
 * @ApiResource(
 *     collectionOperations={"get"},
 *     itemOperations={"get"}
 * )
 */
class Users
{
    /**
     * @var int
     *
     * @ORM\Column(name="id", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var string
     *
     * @ORM\Column(name="nom", type="string", length=128, nullable=false)
     */
    private $nom;

    /**
     * @var int|null
     *
     * @ORM\Column(name="tel", type="bigint", nullable=true, options={"unsigned"=true})
     */
    private $tel;

    /**
     * @var string
     *
     * @ORM\Column(name="email", type="string", length=128, nullable=false)
     */
    private $email;

    /**
     * @var string
     *
     * @ORM\Column(name="addresse", type="text", length=65535, nullable=false)
     */
    private $addresse;

    /**
     * @var int
     *
     * @ORM\Column(name="id_pays", type="integer", nullable=false)
     */
    private $idPays;

    /**
     * @var int
     *
     * @ORM\Column(name="post_code", type="integer", nullable=false)
     */
    private $postCode;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getNom(): ?string
    {
        return $this->nom;
    }

    public function setNom(string $nom): self
    {
        $this->nom = $nom;

        return $this;
    }

    public function getTel(): ?string
    {
        return $this->tel;
    }

    public function setTel(?string $tel): self
    {
        $this->tel = $tel;

        return $this;
    }

    public function getEmail(): ?string
    {
        return $this->email;
    }

    public function setEmail(string $email): self
    {
        $this->email = $email;

        return $this;
    }

    public function getAddresse(): ?string
    {
        return $this->addresse;
    }

    public function setAddresse(string $addresse): self
    {
        $this->addresse = $addresse;

        return $this;
    }

    public function getIdPays(): ?int
    {
        return $this->idPays;
    }

    public function setIdPays(int $idPays): self
    {
        $this->idPays = $idPays;

        return $this;
    }

    public function getPostCode(): ?int
    {
        return $this->postCode;
    }

    public function setPostCode(int $postCode): self
    {
        $this->postCode = $postCode;

        return $this;
    }


}
